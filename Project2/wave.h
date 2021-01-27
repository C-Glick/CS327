#ifndef WAVE
    #define WAVE
    #include "SoundSamples.h"
    #include <string>
    using namespace std;
    class Wave{
        protected:
            string name;
            float frequency;
        public:
            Wave(string nameIn): name(nameIn){}
            SoundSamples* generateSamples(float frequency, float sampleRate, float duration);
            virtual float generateFunction(float time)=0;
    };
#endif