#ifndef SOUND_INCLUDED
    #define SOUND_INCLUDED
    #include "DLL.h"
    
    //the Sound struct holds the actual samples
    //the number of samples (length)
    //and the sample rate
    typedef struct sound_t{
        float* samples;
        int length;
        float rate;
    } Sound;

    //The Wave struct holds details about a wave
    //its name, type, a delay amount, and attenuation
    typedef struct wave_t{
        char* name;
        char* type;
        float delay;
        float attenuation;
    } Wave;

    //the MixedSound struct holds information about the 
    //sound as its defined in the song file
    //name, along with a list of wave *names*, and a list of wave volumes
    typedef struct mixedSound_t{
        char* name;
        LISTPTR waveList;
        LISTPTR waveVolume;
    } MixedSound;

    //the Note struct holds information about each note in a song
    //the name of the sound used for this note, the frequency of the note,
    //the start time of the note, and the duration
    typedef struct note_t{
        char* soundName;
        float frequency;
        float time;
        float duration;
    } Note;

#endif