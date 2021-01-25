#include "soundio.h"
void SoundIO::OutputSound(SoundSamples* samples, string filename){
    ofstream fileOut;
    fileOut.open(filename);

    for(int i = 0; i < samples->getLength(); i++){
        fileOut << (*samples)[i] << "\n";
    }

    fileOut.close();
}
