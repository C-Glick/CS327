#include <iostream>
#include <vector>
#include "soundio.h"
#include "SoundSamples.h"
#include "SawtoothWave.h"
#include "SineWave.h"
#include "SquareWave.h"
#include "TriangleWave.h"
#include "wave.h"
#include <string.h>


int main(int argc, char *argv[]){
    const int sampleRate = 8000;
    string waveType;
    float delay;
    float attenuation;
    float atime;
    float alevel;
    float dtime;
    float slevel;
    float rtime;
    string fileOut;
    vector<int> notes;

    cout << "Default sample rate is 8000 Hz" << endl;
    cout << "Wave type, 1, 2, 3, or 4" << endl;
    cin >> waveType;

    cout << "Reverb delay (seconds)" << endl;
    cin >> delay;

    cout << "Reverb attenuation (0.0 - 1.0)" << endl;
    cin >> attenuation;

    cout << "Attack time (seconds)" << endl;
    cin >> atime;

    cout << "Attack level (0.0 - 1.0)" << endl;
    cin >> alevel;

    cout << "Decay time (seconds)" << endl;
    cin >> dtime;

    cout << "Sustain level (0.0 - 1.0)" << endl;
    cin >> slevel;

    cout << "Release time (seconds)" << endl;
    cin >> rtime;
    
    cout << "File out" << endl;
    cin >> fileOut;

    int tempNote;
    cout << "Note number to play (terminate with a negative)" << endl;
    cin >> tempNote;

   
    while(tempNote > 0){
        notes.push_back(tempNote);
        cout << "Note number to play (terminate with a negative)" << endl;
        cin >> tempNote;
    }

    SoundSamples result = SoundSamples(0, sampleRate);  
    SoundSamples silenceSamples = SoundSamples(0.25 * sampleRate, sampleRate);

    for(auto note = notes.begin(); note!= notes.end(); ++note){
        Wave* currentWave;
        if(waveType.compare("1") == 0){
            currentWave = new SineWave("SineWave");
        }else if(waveType.compare("2") == 0){
            currentWave = new SquareWave("SquareWave");
        }else if(waveType.compare("3")  == 0){
            currentWave = new TriangleWave("TriangleWave");
        }else if(waveType.compare("4") == 0){
            currentWave = new SawtoothWave("SawtoothWave");
        }
        SoundSamples* currentSamples = currentWave->generateSamples(pow(2, ((*note-49)/12.0)) * 440.0, sampleRate, 1);
        currentSamples->asdr(atime, alevel, dtime, slevel, rtime);
        currentSamples->reverb2(delay, attenuation);

        result + *currentSamples;
        result + silenceSamples;

        delete currentSamples;
        delete currentWave;
    }
    SoundIO::OutputSound(&result, fileOut);
    return 0;
}