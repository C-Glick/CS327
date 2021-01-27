# Song player project C++

This is the second project in Com S 327 Advanced Programming. This project seeks to generate music files from
supplied song files. 

## Current Features

- Part A
    - Generate samples for one of four wave types (Sine wave, Square wave, Triangle Wave, or Sawtooth wave)
    - waves can have any sample rate, frequency, or duration
    - Output samples to a text file

## Usage
Clone this repository. In the top level of the repository execute the command `make`. 
This will compile the needed files for **part A** and produce one executable file, `partA`.

`make clean` may be used to remove all executables and .o files.

`partA` Generates wave samples based on the parameters passed in on standard in. The wave types are:

1) Sine Wave
2) Square Wave
3) Triangle Wave
4) Sawtooth Wave

The wave is then generated and the samples are written
to a text file. NOTE: *This output will overwrite any existing file with the same name.* This output file can be converted to a .wav file by using `Waveconverter`.