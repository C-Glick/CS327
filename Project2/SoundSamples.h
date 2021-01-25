#ifndef SOUND_SAMPLES
    #define SOUND_SAMPLES

    class SoundSamples{
        private:
            float rate;
            float* samples;
            int length;

        public:
            /** default constructor */
            SoundSamples();
            /** specific constructor */
            SoundSamples(float* samples, int length, float rate);
            SoundSamples(int length, int rate);
            /** copy constructor*/
            SoundSamples(const SoundSamples& toCopy);

            const float getRate(){return rate;}
            const int getLength(){return length;}
            void reverb2(float delay, float attenuation);
            void asdr(float atime, float alevel, float dtime, float slevel, float rtime);

            /** assignment overloading */
            SoundSamples& operator = (SoundSamples& rhs){
                rate = rhs.rate;
                length = rhs.length;
                delete samples;
                samples = new float[length];
                for(int i=0; i<length; i++){
                    samples[i] = rhs.samples[i];
                }
                return (*this);
            }

            /** [] overloading */
            float& operator [] (int index){
                return  samples[index];
            }

            /** addition overloading appends samples of rhs to lhs */
            SoundSamples& operator + (SoundSamples& rhs){
                float* temp = new float[length + rhs.length];
                //copy current values to temp
                for(int i=0; i<length; i++){
                    temp[i] = samples[i];
                }
                //append new values to temp
                for(int i=length; i<length + rhs.length; i++){
                    temp[i] = rhs.samples[i-length];
                }
                length += rhs.length;
                //delete old samples
                delete samples;
                //assign new samples
                samples = temp;
                return *this;
            }
    };
#endif