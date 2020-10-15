- history / philosophy
	- invented by Bjorne straustrup in early 1980's
		- implementing an event driven simulation and wanted an OO language
		- wanted speed and efficiency
	- philosophy
		- retain as much of C as possible
			- still has pointers and seg faults, still doesn't have a string type :(
			- doesn't have array bounds checking
			- doesn't have garbage collection
			- does have destructors within objects to clean up objects
		- don't pay for unused features
		- programmer is always right
	- strengthen type checking (force some casting)
	- cleans up some syntax
	- adds some features "to make programming easier"
		- references
		- classes
		- templates
		- exceptions
		- name spaces
		- function and operator overloading
		- OO style IO
- bool type for booleans 
	- constants true and false
	- bool is still and integer, 1=true 0=false
- casting 
	- still do it the C way 
		- i = (int) x;
	- or (casting x to an int):
		- typename(exp)
		- i = int(x); 
		- i = int(x * 3.31);
- structs
	- when declaring, can use the name of the struct to declare variables/parameters
		```c++
		
		struct date{
			short year;
			char month;
			char day;
		};
		
		date today;
		today.day = 'm';
		
		```
- type checking
	- stronger checking than C
	- enumerated types
		```C++
		enum permisssions{
			read = 4;
			write = 2;
			execute = 1;
		}
		
		permission group = write;	//normal way
		permission group = 2; 		//ILLEGAL
		permission group = permission(2);	//works
		```
- Big differences
	- I/O
		- can still use stdio.h to do input/output including printf and scanf
		- C++ users streams(objects)
			- streams have methods 
			- can get / put items on/off the stream
			- output streams
				- writing files, stdout, stderr
			- input streams
				- reading from a file or stdin
	- constants
		- `const` key word, available in C
		- can appear in many different locations and each means something else
	- [[References]]
		- different than pointers
		- sort of like pointers
		- must be initialized immediately
		- cannot be NULL
		- can never be reassigned
	- classes
		- real objects (and everything that goes with it)
		- define it like a struct but user keyword `class`
		- in addition to data, has methods
		- header files typically used to define the "interface" to the class
	- function overloading
		- have two or more functions with the same name 
		- resolve which one to use based on parameters
		- can overload 
			- functions
			- member methods
			- constructors
			- operators (+, -, +=, [], -> etc)
	- method parameters can have default values if they are not passed in
		- `int increment (int a, int delta = 1){return a + delta;}`
	- strings
		```C++
		#include <string>
		#include <iostream>
		using namespace std;
		
		int main(){
			string mystring;
			cout << "what is your name?";
			getline(cin, mystring);	//reads the first line from cin into mystring
		}
		```
		- has string.length and others
		- most of what is in java is in C++
		- 