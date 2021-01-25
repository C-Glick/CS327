#ifndef SOUND_IO
    #define SOUND_IO
    #include "SoundSamples.h"
    #include <string>
    #include <iostream>
    #include <fstream>

    using namespace std;
    class SoundIO{
        public:
            static void OutputSound(SoundSamples* samples, string filename);
    };
#endif