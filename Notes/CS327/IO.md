## standard IO
will use fprintf and fscanf from stdio.h
- fprintf(File pointer, format string, ....);
- fscanf()
	- returns # of correctly read items
- standard File pointer (descriptors)
	- stdout
		- printf() is the same as fprintf(stdout, ....)
	- stderr
		- ex: fprintf(stderr, .....);
		- doesn't not get redirected to output files with > or >>
	- stdin
		- scanf() is the same as fscanf(stdin, ....)
- can also use fscanf and fprintf to read and write to files
	- Used commonly with command line arguments to read and write to files
	- EX:
		```c
		#include <stdio.h>
		//^defines NULL = 0
		
		int main(int argc, char* argv[]){
			FILE* outfile;
			//associate pointer with a file
			outfile = fopen("zebra.txt", "w");
			if(outfile == NULL){
				fprintf(stderr, "Could not open file\n\n");
				exit(1);
			}
			fprintf(outfile, "Square Table\n\n");
			for(int i=0; i<10; i++){
				fprintf(outfile, "%d %d\n", i, i*i)
			}
			fclose(outfile);
		}
		```
		
		![[Pasted image 1.png]] goes to the file 
- fopen(\<file path>, \<mode>)
	- file path can be relative or absolute
	- modes
		- w, write erase everything else in file
		- a, append to end of file
		- r, read
	- returns a pointer to a structure that describes the file
	- returns null if for some reason the file could not be opened (being used by some other program)
		- should check that it is not null after opening 
	- will create file if doesn't existin write and append mode
- fclose(\<file pointer>)
	- close the file and write everything to it, safer and good practice to use
- I/O is buffered, doesn't get immediately written to disk, stores in memory first
	- can flush the buffer to the output with `fush()` and `fflush(FLIE*)`
- reading from a file ex:
	```c
	#include <stdio.h>
	main(int argc, char *argv[]){
		FILE* readfile;
		//check if there are terminal arguments
		if(argc > 1){
			readfile = fopen(argv[1], "r");
			//should test for valid file
		}else{
			readfile = stdin;
		}
		float input1, input2;
		fscanf(readfile, "%f %f", &input1, &input2);
	}
	```