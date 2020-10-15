- can have any number of classes per file with any names
- but does have some conventions
	- two files for each class
		- .h files, class declaration, member variables, method prototypes, macros, (sometimes inline functions)
		- .cpp files, implementation of methods
- EX:
	```cpp
	class Box{
		//may have multiple sections of each and in any order
		private:
			int val;
			
		public:
			int myVeryBadIdea;
			
			//constructor
			Box (int v){
				val = v;
			}
			
			//getter for value
			inline int value(){
				return val;
			}
		
		protected:
			.
			.
			.
	}; //NOTE SEMI COLON at the end of the class
	```
	
	- inline key word
		- request the compiler to not make a function call, just fill in code
		- normally calls a subrutines to call the function
		- replaces the function call with the code in the function
	- getters and setters are good places to use this
		- `inline int getter(){ return x;}`
	- counter example
		```cpp
		------counter.h-------
		
		#ifndef COUNTER_H
			#define COUNTER_H
			
			class Counter{
				private:
					int value;
					int maxValue;
				public:
					Counter();
					Counter(int);
					void setValue(int);
					void increment();
					void decrement();
					int getValue() const;	//note const keyword, means this method cannot make changes to the class member
					inline int getMaxValue() const{
						return maxValue;
					}
			};
		#endif
		```
		
		```cpp
		------Counter.cpp-------
		#include <iostream>
		#include <limits>
		#include "Counter.h"
		using namespace std;
		
		//need to fully qualify object methods with Counter::
		
		Counter::Counter(){	
			value = 0;
			maxValue = INT_MAX;
		}
		
		Counter::Counter(int max){
			value = 0;
			maxValue = max;
		}
		
		void Counter::setValue(int val){
			if((val)>=0 && (val <= maxValue)){
				value = val;
			}else{
				cerr << "Set value out of range " << val << endl;
			}
		}
		
		void Counter::increment(){
			if(value < maxValue){
				value++;
			}else{
				cerr << "Counter overflow" << endl;
			}
		}
		//insert other methods here
		
		```
		
		```cpp
		------CounterTest.cpp--------
		#include <iostream>
		#include "Counter.h"
		using namespace std;
		
		int main(){
			Counter c1;		//calls the default constructor
			Counter c2(10); //calls other constructor initializes with 10
			
			c1.setValue(50);
			c1.decrement();
			c1.increment();
			
			cout << "c1 final value = " << c1.getValue() << endl;
		}
		
		int main(){
			Counter c1;
			Counter c2(10);
			c1.setValue(50);
			c1.increment();
			c2 = c1; 	//NOTE: this calls a new kind of constructor, the copy constructor, copies c1 into c2
			//BEWARE: if stack objects (and some others) crazy things can happen
		}
		```
		- compiling, very similar to C
			- `g++ -g Counter.cpp CounterTest.cpp -o counterTest`
			- -g is for debugging
			- -c to generate .o files
			- with make:
				```
				counterTest: Counter.o counterTest.o
					g++ -g -o counterTest Counter.o CounterTest.o
				
				Counter.o: Counter.cpp Counter.h
					g++ -g -c Counter.cpp
				
				CounterTest.o: CounterTest.cpp Counter.h
					g++ -g -c CounterTest.cpp
				```
			- const keyword
				- `const int c = 42;`
				- cannot change the value later
				- `const int * c1;`
					- a variable pointer to a constant integer
				- `int const * c2`
					- same, variable pointer to a constant int
				- `int * const c3;`
					- **constant pointer** to a **variable int**
				- `int cost * const c4;`
					- both are constant
				- rule of thumb
					- const applies to whatever is on the left unless there is nothing on the left in which case it applies to the right cause why not -_-
- function paramaters with const
	- void compute(struct data* p)
	- but we dont want the data changed that p points to
	- use
		- void compute (const struct data* p)
	- c++ can use const to control access to member variables
	- getters should always use const,
		- void Complex::getReal() const
- references types