- unions
	- can treat one variable as multiple different types, saved in the same memory
	``` c
	union tag2{
		int a;
		char *b;
	}
	union tag2 y;
	y.a = 1;
	y.b = '\n';
	printf("%d\n",y.a);
	//will print the ascii of the new line character, 10
	//because y.b = '\n' overwrites 1
	```
- bit fields
	- |= is a bitwise or and assigns it to props
	```c
	#define IS_DOG 1
	#define IS_FISH 2	//b00000010
	#define IS_LONG 4
	#define HAS_TAIL 8
	
	int props = 0;
	props |= IS_DOG;
	props |= HAS_TAIL;
	
	if(props & IS_LONG){
		...
	}
	```
	
	bit fields in a struct
	```c
	struct bitfieldex{
		unsigned int prop1:1;	//:1 = use 1 bit of this variable
		unsigned int prop2:1;
		unsigned int prop3:2;
	} bitfields;
	
	bitfields.prop1 = 0;
	bitfields.prop2 = 1;
	bitfields.prop3 = 2;
	
	```
	
	struct bit field inside a union, allows more functionality from bit fields
	```c
	union flagdef{
		struct{
			unsigned int prop1:1;
			unsigned int prop2:1;
			unsigned int prop3:2; 
		} bitfields;
		unsigned int flags;	
	};
	
	union flagdef x;
	
	//reset all
	x.flags = 0;
	
	//set one property
	x.bitfields.prop1 = 1;
	```
	
- Macros 
	```c
	#define foo cat //everywhere the preprocessor sees "foo" replaces it with "cat"
	#define max(A, B) ((A)>(B))?(A):(B)		//A and B can be any variable the name doesnt matter
	
	```