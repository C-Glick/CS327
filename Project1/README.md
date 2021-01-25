# Dial Tone Project

This is the first project in Com S 327 Advanced Programming. This project seeks to recreate the dial tones from phone lines.

## Current Features
- Part A
    - Output is represented as floating point numbers printed on standard out
    - Generate sin waves of any frequency, sample rate, and length
    - Generate a dial tone for a 10 digit integer sequence
- Part B
    - Generate tones of any length based on command line parameters
    - Output tones to a specified file instead of standard out

## Usage
Clone this repository. In the top level of the repository execute the command `make`. 
This will compile the needed files and produce three executable files, `gensine`, `gendial`, and `dtmf`.

To compile only files from part A, `make parta` may be used.
Likewise, to compile only files from part B, `make partb` may be used.

To compile only one of the executables, `make gensine`, `make gendial`, or `make dtmf` may be used.
`make clean` may be used to remove all executables and .o files.

`gensine` generates a sin wave of any frequency, sample rate, and length.
Run it with the following command `./gensine` and enter the required parameters when prompted.

`gendial` generates a dial tone for a 10 digit phone number.
Run it with the following command `./gendial` and enter the phone number when prompted. 
Valid characters are case insensitive and include: `1, 2, 3, 4, 5, 6, 7, 8, 9, 0, a, b, c, d, #, and *`

`dtmf` generates a dial tone based on the command line argument passed in.
Usage: `./dtmf <number to dial> <(optional) output file>`
The number may be of any length but can only contain 0-9, a-d, #, or \*.
The output file is optional. If specified, the samples will be written to this file
instead of standard out. NOTE: *This will overwrite any existing file with the same name*

## See [DEVELOPER.md](DEVELOPER.md) for details on individual functions