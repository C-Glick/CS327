## pointers
- 
	```c
	void swap(int a, int b){
		int temp=a;
		a=b;
		b=temp;
	}
	
	void swap_with_ptr(int* a, int* b){
		int temp = *a;	//get the value which a points to
		*a = *b		//set the value which a points to, to the value which b points to
		*b = temp; 	//set the value which b points to, to temp
	}
	```
	- swap wont work because a and b are local variables
	- a and b are value parameters, they are **copied** from where it was called
	- need to use *pointers* to do this swap, sending the address to the function
	- consider the following
	```c
	#include <stdio.h>
	
	main(){
		int v1;
		int v2;
		char c;
		char name[5];
		.
		.
		.
		int *p; //pointer to an int
		p = &v1;
	}
	
	```
	
	|address| variable|value|
	|--------|---------|------|
	|1|v1|
	|2|v1
	|3|v1|
	|4|v1|
	|5|v2|
	|6|v2|
	|7|v2|
	|8|v2|
	|9|c|
	|10|name|
	|11|name\[0]|
	|12|name\[1]|
	|13|name\[2]|
	|14|p|1|
	
	- ### operators
		- & reference operator
			- return the address location of the following variable
			- &var == 0x224ad42
		- * dereference operator
			- follow the pointer and return the value at that address 
			- \*ptrVar == (value of var here) 
	- #functionPointer
		- float (\*opfunc)(float, float)
		^expects a pointer to a function with two float arguments