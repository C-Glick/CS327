 ## bitwise operators
 - #bitwise
	- operate on the binary representation of the int
	- ~ ones complement
	- & bitwise AND
	- | bitwise OR
	- ^ bitwise XOR
	- << left shift
	- \>> right shift
	- ex:
		- 8 bit unsigned char
		- char x = 0x96 = 1010 0110
		- char y = 0x28 = 0010 1000
		- ~x = 0101 1001
		- x & y = 0010 0000
		- x | y = 1010 1110 
	- useful for
		- high data compression, set and test individual bits
		- embedded systems
- other operators
	- +=
	- -=
	- *=
	- ^=
	- /=
	- %=
	- &=
	- ++ and --
		- post increment and pre increment can be tricky
- conditional operator
	- a?b:c
		- evaluates based on the condition
		- test condition? true value: false value
	- EX: max = (x>y)?x:y


## local and global variables
- 
	- local variables are declared inside functions (or in blocks inside functions)
		- can only be used inside that function/block
	- global variables are defined outside functions
		- can be used any time by any function
		- common to declare at the beginning of the file
		- to use global declared in one file from another, have to declare it as "extern"
	- EX:
		```c
		#include <stdio.h>
		
		void testVar(){
			int a;
			prnitf("%d\n", a);
			a=55
		}
		
		void writeVar(){
			int b;
			b = 42;
		}
		
		void main(){
			testVar();
			testVar();
			testVar();
			testVar();
			testVar();
			writeVar();
			testVar();
		}
		```
		
		output:
		```
		0
		55
		55
		55
		55
		42
		```
	 - explanation
		 - declares memory for a, then prints garbage, then assign 55 to memory
		 - the next time reassign a to be the same location and prints 55
		 - the b variable was assigned to the same place as b and assigns to 42
		 - because a was not initlized before it was print it used what ever was in the memory, happened to be 42 from writeVar
	 - local static variables
		 - a variable that is declared static inside a function is still scoped to that function but it maintains its value between function calls
		
		
## assignment statements
- 
	- assignments return the value they assign
	- watch out for this
	```c
	if(t<32){
		printf("below freezing");
	}else{
		printf("above freezing")
	}
	
	//can also do
	
	if(a=1){   //ERROR: this assignes a to 1 and returns 1, will always be true
		printf("a is 1")
	}
	```
	 - can also happen with switch and while statements
	```c
	while (a=3){	//ERROR: infinite loop
		//do stuff
	}
	```




## GOTO
- try not to use

## Prototypes
- 
	```c
	#include <stdio.h>
	
	void prnt_converted(int pounds){
		int stones = pounds/14;
		int uklbs = pounds%14;
		float kg_per_pounds = 0.45359;
		float kilos = pounds * kg_per_pound;
		printf(-------------);
	}
	
	main(){
		int tablesize, pounds, index;
		printf("enter table size: ");
		
		scanf("%d", &tablesize); //expects a memory location
		
		for(pounds = 10, index=0; index < tablesize; index++){
			prnt_converted(pounds);
		}
	}
	```
	- .h files aka header files have prototypes 
	 ```c 
	 print_converted(int);
	 ```
	 
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
	