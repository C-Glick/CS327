# COM S 327 Take Home Exam
This program parses a candy store inventory file and outputs details on the different types of candy.

The program can be built by running `make` in the top level directory of the project. This will generate all of the required .o files as well as 1 executable called `candy`.

`make clean` may also be used to clean up any .o files and executables

Usage: `./candy <candy data base file>`

Further details and documentation for each class can be found in the DEVELOPERS file, in header files for the classes, and in Main.cpp.

## Input file format
The input file must be a specific format for the program to function correctly. A candy definition must be surrounded by `START` and `END` on their own lines. Text outside of these borders is ignored. There can be any number of blank lines after `START` or before `END` but there must be no blank lines between parameters when defining a candy. There can be multiple candy definitions in one `START END` block with any number of blank lines between them.

Every candy has the following parameters defined in this order on their own line:
 - Candy name
    - Any string, spaces are fine
 - Candy type
    - "jelly"
    - "caramel"
    - "chocolate"
    - "hard"
 - Price type
    - "piece"
    - "pound"
 - Price
    - Any floating point number
    - represents dollars / unit
 - Color (only for hard and jelly candy, omit for other types)
    - a number between 0 and 9
    - 0 indicates no color
 - Amount
    - An integer count of the quantity in the store
    - pieces or ounces depending on the price type
 - Calories
    - A floating point number that represents the number of calories in one unit of candy


## Example input
```
>this text is ignored<
jolly ranchers
-------------------
START



Jolly Rancher
hard
piece
0.50
1
2123
100

Jolly Rancher
hard
piece
0.50
2
1032
100

Jolly Rancher
hard
piece
0.50
3
976
100

END


should do nothing
blah 
blah 
blah

START
M&Ms
chocolate
pound
2.59
100
250
END

gummy Bears
----------------

START
Gummy Bears
jelly
pound
5.34
4
60
580

Gummy Bears
jelly
pound
5.34
5
60
580

END

START

Butterworths
caramel
pound
5.01
142
200

END
```