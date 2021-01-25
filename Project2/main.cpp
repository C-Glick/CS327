#include <iostream>
#include "soundio.h"
#include "SoundSamples.h"
#include "SawtoothWave.h"
#include "SineWave.h"
#include "SquareWave.h"
#include "TriangleWave.h"
#include "wave.h"
#include <string.h>


using namespace std;
int main(int argc, char *argv[]){
    string waveType;
    float sampleRate;
    float frequency;
    float duration;
    string fileOut;

    cout << "Wave type, 1, 2, 3, or 4" << endl;
    cin >> waveType;

    cout << "Sample rate" << endl;
    cin >> sampleRate;
    
    cout << "Frequency" << endl;
    cin >> frequency;

    cout << "Duration" << endl;
    cin >> duration;
    
    cout << "File out" << endl;
    cin >> fileOut;

    Wave* w;


    if(waveType.compare("1") == 0){
        w = new SineWave("SineWave");
    }else if(waveType.compare("2") == 0){
        w = new SquareWave("SquareWave");
    }else if(waveType.compare("3")  == 0){
        w = new TriangleWave("TriangleWave");
    }else if(waveType.compare("4") == 0){
        w = new SawtoothWave("SawtoothWave");
    }

    SoundSamples* sound = w->generateSamples(frequency, sampleRate, duration);
    SoundIO::OutputSound(sound, fileOut);
}
