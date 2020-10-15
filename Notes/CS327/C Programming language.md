- [[Pointers]]
- [[Bitwise]]
- [[IO]]


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
	 