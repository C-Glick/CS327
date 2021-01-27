#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "gensnd.h"
#include "iosnd.h"
#include "process.h"
#include "DLL.h"

//trim whitespace at the beginning and end of the given char pointer
//returns the trimmed string
char* trimString(char* in){
    //trim the end
    char* end = in + strlen(in);
    while(isspace(*--end));
    *(end+1) = '\0';

    //trim the front
    while(isspace(*in)) in++;
    return in;
}

//print the given list to standard out, data is assumed
//to be Wave pointers each node
void printListWaves(LISTPTR list){
    printf("----WaveList start----\n");
    for(int i=0; i < list->numItems; i++){
        printf("%s\n",(*(Wave *)get(list, i)).name);
        printf("%s\n",(*(Wave *)get(list, i)).type);
        printf("%f\n",(*(Wave *)get(list, i)).delay);
        printf("%f\n\n",(*(Wave *)get(list, i)).attenuation);
    }
    printf("----WaveList end----\n");
}

//print the given list to standard out, data is assumed
//to be MixedSound pointers at each node
//prints each sound and its waves
void printListSounds(LISTPTR list){
    printf("----Sound List----\n");
    for(int i=0; i < list->numItems; i++){
        printf("%s\n",(*(MixedSound *)get(list, i)).name);
        printListStrings((*(MixedSound *)get(list, i)).waveList);
        printListFloats((*(MixedSound *)get(list, i)).waveVolume);
    }
    printf("----SoundList end----\n");
}

//print the given list to standard out, data is assumed
//to be MixedSound pointers at each node
//prints each sound and its waves
void printListNotes(LISTPTR list){
    printf("----Note List----\n");
    for(int i=0; i < list->numItems; i++){
        Note* note = (Note *)get(list, i);
        printf("%s ",note->soundName);
        printf("%f ",note->frequency);
        printf("%f ",note->time);
        printf("%f\n",note->duration);
    }
    printf("----noteList end----\n");
}

//sorts the note list given based on the start time 
//of each note
void selectionSortNoteList(LISTPTR list){
    for (int i=0; i < list->numItems-1; i++){
        float min = ((Note*)get(list, i))->time;
        int minIndex = i;

        for(int j = i + 1; j < list->numItems; j++){
            if(((Note*)get(list, j))->time < min){
                min = ((Note*)get(list, j))->time;
                minIndex = j;
            }
        }
        swap(list, i, minIndex);
    }
}

//inserts the toInsert sound into the masterSound sound at the given sample number
//adds existing samples together
//can produce samples values out of the range -1 to 1
void insertSound(Sound* masterSound, Sound* toInsert, int insertSamplePoint){
    if(masterSound->rate != toInsert->rate){
        fprintf(stderr, "output mixing error: sounds passed in are not the same sample rate.");
        return;
    }

    //if masterSound samples needs to be extended
    if(toInsert->length + insertSamplePoint > masterSound->length){
        int oldLength = masterSound->length;
        masterSound->length = toInsert->length + insertSamplePoint;
        masterSound->samples = realloc((masterSound->samples), sizeof(float) * masterSound->length);

        //zero out new values
        for(int i = oldLength; i < masterSound->length; i++){
            masterSound->samples[i] = 0;
        }
    }

    //add toInsert values into masterSound
    for(int i = 0; i < toInsert->length; i++){
        masterSound->samples[i + insertSamplePoint] += toInsert->samples[i]; 
    }

}

//search through the given waveList for a wave with the 
//given name
Wave* findWaveByName(LISTPTR waveList, char* searchName){
    NODEPTR currentWave = waveList->head->next;
    while(currentWave != waveList->head){
        if(strcmp(((Wave*)currentWave->data)->name, searchName) == 0){
            return (Wave*)currentWave->data;
        }
        currentWave = currentWave->next;
    }
    fprintf(stderr, "findWaveByName error: could not find wave with name: %s\n", searchName);
    return NULL;
}

//search through the given soundList for a wave with the 
//given name
MixedSound* findSoundByName(LISTPTR soundList, char* searchName){
    NODEPTR currentSound = soundList->head->next;
    while(currentSound != soundList->head){
        if(strcmp(((MixedSound*)currentSound->data)->name, searchName) == 0){
            return (MixedSound*)currentSound->data;
        }
        currentSound = currentSound->next;
    }
    fprintf(stderr, "findSoundByName error: could not find sound with name: %s\n", searchName);
    return NULL;
}

//main program
int main(int argc, char *argv[]){
    if(argc < 3){
        fprintf(stderr, "Converts song text files into raw samples that can then be converted into a wav file.\n");
        fprintf(stderr, "usage: playsong <song file in> <sample file out>\n");
        exit(EXIT_SUCCESS);
    }

    int sampleRate = 0;
    //wave list holds the defined waves for this song file
    //uses the Wave struct 
    LISTPTR waveList = createList();
    //sound list holds the defined sounds for this song file
    //uses the MixedSound struct
    LISTPTR soundList = createList();
    //list of notes contained in the song
    //uses the Note struct
    LISTPTR noteList = createList();


    FILE* fileIn = fopen(argv[1], "r");
    if(fileIn == NULL){
        fprintf(stderr, "read error: could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t lineSize;

    //read input file line by line
    while ((lineSize = getline(&line, &len, fileIn)) != -1) {
        
        line = trimString(line);
        
        //test for key words
        if(strstr(line, "SAMPLERATE")){
            lineSize = getline(&line, &len, fileIn);
            line = trimString(line);
            sampleRate = atoi(line);
        }else if(strstr(line, "WAVE")){
            Wave* wave = malloc(sizeof(Wave));
            wave->name = malloc(sizeof(char) * 255);
            wave->type = malloc(sizeof(char) * 10);

            lineSize = getline(&line, &len, fileIn);
            strcpy(wave->name, trimString(line));

            lineSize = getline(&line, &len, fileIn);
            strcpy(wave->type, trimString(line));

            lineSize = getline(&line, &len, fileIn);
            line = trimString(line);
            //split the line on spaces and set the first item to delay
            wave->delay = strtof(strtok(line, " "), NULL);
            //call on null to continue last string, set to attenuation
            wave->attenuation = strtof(strtok(NULL, " "), NULL);

            add(waveList, wave);
        }else if(strstr(line, "SOUND")){
            MixedSound* sound = malloc(sizeof(MixedSound));
            sound->name = malloc(sizeof(char) * 255);
            sound->waveList = createList();
            sound->waveVolume = createList();

            lineSize = getline(&line, &len, fileIn);
            strcpy(sound->name, trimString(line));
            
            lineSize = getline(&line, &len, fileIn);
            line = trimString(line);

            while(strcmp(line, "") != 0){
                //set name of wave
                char* waveName = malloc(sizeof(char) * 255);
                strcpy(waveName, strtok(line, " "));
                add(sound->waveList, waveName);

                //set volume of wave
                float* waveVolume = malloc(sizeof(float));
                *waveVolume = strtof(strtok(NULL, " "), NULL);
                add(sound->waveVolume, waveVolume);

                lineSize = getline(&line, &len, fileIn);
                line = trimString(line);

            }

            add(soundList, sound);
        }else if(strstr(line, "SONG")){
            //start of song section, continue to end of file
            while ((lineSize = getline(&line, &len, fileIn)) != -1) {
                line = trimString(line);
                //line is not blank
                if(strcmp(line, "") != 0){
                    Note* note = malloc(sizeof(Note));
                    note->soundName = malloc(sizeof(char) * 255);
                    //split string and get the name
                    strcpy(note->soundName, strtok(line, " "));
                    //get next string token, int keynumber
                    int key = atoi(strtok(NULL, " "));
                    //convert from keynumber to note frequency
                    note->frequency = pow(2, ((key-49)/12.0)) * 440.0;
                    //get float time
                    note->time = strtof(strtok(NULL, " "), NULL);
                    //get float duration
                    note->duration = strtof(strtok(NULL, " "), NULL);

                    //add the note to the note list
                    //will sort by start time later
                    add(noteList, note);
                }
            }
        }
    }
    //end of file, everything read
    //close file
    fclose(fileIn);

    //sort note list by the start time
    selectionSortNoteList(noteList);

    //sound to output at the end of mixing
    Sound* masterSound = malloc(sizeof(Sound));
    masterSound->rate = sampleRate;
    masterSound->length = 1;
    masterSound->samples = calloc(1, sizeof(float));

    //walk through note list, generates output
    //and adds to masterSound
    NODEPTR notePtr = noteList->head->next;
    while(notePtr != noteList->head){
        Note* note = (Note*)notePtr->data;
        MixedSound* sound = findSoundByName(soundList, note->soundName);

        Sound* waves[sound->waveList->numItems];
        float volume[sound->waveList->numItems];

        //generate waves in the sound for the current note
        for(int i=0; i < sound->waveList->numItems; i++){
            Wave* wave = (Wave*) findWaveByName(waveList, get(sound->waveList, i));
            
            Sound* generated;

            if(strcmp(wave->type, "sine") == 0){
                generated = gensine(note->frequency, sampleRate, note->duration);
            }else if(strcmp(wave->type, "square") == 0){
                generated = genSquare(note->frequency, sampleRate, note->duration);
            }else if(strcmp(wave->type, "triangle") == 0){
                generated = genTriangle(note->frequency, sampleRate, note->duration);
            }else if(strcmp(wave->type, "saw") == 0){
                generated = genSawtooth(note->frequency, sampleRate, note->duration);
            }

            Sound* processed;
            //apply reverb or echo to wave
            if(wave->delay > 0.1){
                processed = echo(generated, wave->delay, wave->attenuation);        
            }else{
                processed = reverb(generated, wave->delay, wave->attenuation);
            }

            //discard generated
            free(generated->samples);
            free(generated);

            waves[i] = processed;
            volume[i] = *((float *)get(sound->waveVolume, i));
        }

        //mix waves together
        Sound* mixedWaves = mix(waves, volume, sound->waveList->numItems);

        //discard processed waves
        for(int i = 0; i < sound->waveList->numItems; i++){
            free(waves[i]->samples);
            free(waves[i]);
            waves[i] = 0;
        }

        //insert mixedWaves into the masterSound
        insertSound(masterSound, mixedWaves, note->time * sampleRate);

        //discard mixedWaves
        free(mixedWaves->samples);
        free(mixedWaves);

        //go to the next note and repeat
        notePtr = notePtr->next;
    }

    //finally output to the file given in command line
    FILE* fileOut = fopen(argv[2], "w");
    if(fileOut == NULL){
        fprintf(stderr, "write error: could not open file %s\n", argv[2]);
    }else{
        outputSound(masterSound, fileOut);
    }
    fclose(fileOut);
    
    //---------cleanup------------

    //free the master sound
    free(masterSound->samples);
    free(masterSound);

    //free note structs
    NODEPTR currentNote = noteList->head->next;
    while(currentNote != noteList->head){
        free(((Note*)currentNote->data)->soundName);
        free(currentNote->data);
        currentNote = currentNote->next;
    }
    deleteList(noteList);

    //free soundList structs
    NODEPTR currentSound = soundList->head->next;
    while(currentSound != soundList->head){
        free(((MixedSound*)currentSound->data)->name);

        //free wave names in sound Struct
        NODEPTR currentWave = ((MixedSound*)currentSound->data)->waveList->head->next;
        while(currentWave != ((MixedSound*)currentSound->data)->waveList->head){
            free(((char*)currentWave->data));
            currentWave = currentWave->next;
        }
        deleteList(((MixedSound*)currentSound->data)->waveList);

        //free wave volume floats
        NODEPTR currentNode = ((MixedSound*)currentSound->data)->waveVolume->head->next;
        while(currentNode != ((MixedSound*)currentSound->data)->waveVolume->head){
            free(((float*)currentNode->data));
            currentNode = currentNode->next;
        }
        deleteList(((MixedSound*)currentSound->data)->waveVolume);

        currentSound = currentSound->next;
    }
    deleteList(soundList);

    //free waveList structs
    NODEPTR currentWave = waveList->head->next;
    while(currentWave != waveList->head){
        free(((Wave*)currentWave->data)->name);
        free(((Wave*)currentWave->data)->type);
        free(currentWave->data);
        currentWave = currentWave->next;
    }
    deleteList(waveList);


    return 0;
}