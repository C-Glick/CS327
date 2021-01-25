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
		- normally calls a subroutines to call the function
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
- function parameters with const
	- void compute(struct data* p)
	- but we dont want the data changed that p points to
	- use
		- void compute (const struct data* p)
	- c++ can use const to control access to member variables
	- getters should always use const,
		- void Complex::getReal() const



------------------
- special methods
	- constructors
		- initializers in constructors 
			```c++
			//normal constructor
			Triple::Triple(int p1=0, int p2=0, int p3=0){
				v1 = p1;
				v2 = p2;
				v3 = v3;
			}
			
			//other constructor
			//note that there is no guarentee on the order 
			//of initialization
			Triple::Triple(int p1=0, int p2=0, int p3=0):
				v1(p2), v2(p2), v3(p3)
				{}
			```
	- destructor
		- called when an object goes out of scope
		- the destructor for a class is called whenever an object of the class goes out of scope or is deleted from the heap.
		- it is used to free any resources used by the object and in particular this means freeing allocated heap memory used by the object
		- c++ automatically supplies a default constructor if you don't define one
			- behavior: apply (call) a destructor on each member variable if possible
			- primitive types (including pointers to objects) do nothing  
		```c++
		~Box();
		```
	- copy constructor
		- copies one object to another
		- special constructor used to construct a new object that is initialized from another object of the same type
		- when called
			- `Box copy = original` or `Box copy(original)`
			- when a object is passed (or returned) into (from) a method or function by value
		- default behavior
			- apply the copy constructor to all member variables of the object
			- note primitive types including pointers are copied by value (shallow copy)
		```c++
		Box(const Box& rhs);
		```
	-  operator = 
		-  copy assignment operator
		-  assigns contents to something (not by reference)
		-  applied to two already constructed objects
		-  `copy = original`
		-  primitives and pointers are copied by value
		```c++
		const Box& operator = (const Box& rhs);
		```
- examples:
	```C++
	Triple.h
	-------------------
	class triple{
		private:
			int v1;
			int v2;
			int v3;
		public:
			~Triple();	//destructor
			Triple(int, int, int);	//constructor
			Triple(const Triple&)	//copy constructor
			const Triple& Triple::operator = (const Triple& rhs)
	}
	
	Tripple.cpp
	------------------
	Triple::~Triple()
	{}	//dont need to do anything becuase only using primitives
	
	Triple::Triple(int p1, int p2, int p3):
		v1(p1), v2(p2), v3(p3){}	//using initilizers in the header instead of in the body
		
	Triple::Triple(cost Triple& rhs):
		v1(rhs.v1), v2(rhs.v2), v3(rhs.v3) //using initilizers 
		{}
	
	const Triple& Triple::operator = (const Triple& rhs){
		if(this != &rhs){ //test if not the same object, 'this' is a pointer to the current object
			//delete the current data in this object, watch out for head allocation
			//copy the data from rhs to this 
			v1 = rhs.v1;
			v2 = rhs.v2;
			v3 = rhs.v3;
		}
		return *this; //dereference 'this' pointer and return the actual object
	} 
	```
	
	```C++
	intbox.h
	--------------------
	#ifndef INTBOX_H
		#define INTBOX_H
		
		class IntBox{
			//stores the value of an int on the heap
			private:
				int* storedValue;
			public:
				IntBox(int); //constructor
				IntBox(const IntBox&); //copy constructor
				~IntBox(); //destructor
				const IntBox& operator = (const IntBox&); //= override
				int value();
		};
		
	#endif
	
	
	intbox.cpp
	--------------------
	IntBox::IntBox(int intValue = 0){	//constructor with default of 0
		storedValue = new int(intValue);	//creates a new int on the heap
	}
	
	IntBox::IntBox(const IntBox& rhs){	//copy constructor
		storedVale = new int(rhs->storedValue);
	}
	
	IntBox::~IntBox(){	//destructor
		delete(storeValue);		//free the memory on the heap
	}
	
	const IntBox& IntBox::operator = (const IntBox& rhs){	//deconstructor
		if(this != &rhs){
			*storedValue = *rhs.storedValue; 	//copies the stored value from other object into this object
		}
		return *this;
	}
	
	int IntBox::value(){
		return *storedValue;
	}
	
	```
	
	integer linked list queue
	----------------------------
	```C++
	queue.h
	-------------------
	#ifndef NULL
		#define NULL
	#endif
	
	class ListNode{
		public:
			int element;
			ListNode *next;
			ListNode(int theElement, ListNode *next = NULL):
				element(theElement), next(next){}		
	};
	
	class UnderflowException{
	};
	
	
	class intQueue{
		private:
			int size;
			ListNode* front;
			ListNode* back;
			void makeEmpty();
		public:
			intQueue();
			~IntQueue();
			const IntQueue& operator = (const IntQueue& d);
			//TODO: copy constructor
			bool isEmpty();
			int getFront();
			void enqueue(int);
			int dequeue();
			void printQueue();
	};
	
	
	queue.cpp
	--------------
	#include "queue.h"
	
	IntQueue::IntQueue():
		front(NULL), back(NULL), size(0){}
	
	IntQueue::~IntQueue(){	//destructor
		makeEmpty();
	}
	
	void IntQueue::makeEmpty(){
		while(!isEmpty()){
			dequeue();
		}
	}
	
	const IntQueue& IntQueue::operator = (cost IntQueue rhs){
		if(this != &rhs){
			makeEmpty();
			ListNode *rptr = rhs.front;
			while(rpty != NULL){
				enqueue(rptr->element);
				rptr = rptr->next;
			}
		}
		return *this;
	}
	
	inline bool IntQueue::isEmpty(){
		return front == NULL;
	}
	
	int IntQueue::getFront(){
		if(isEmpty()){
			throw new UnderflowException();
		}
		return front->element;
	}
	
	void IntQueue::enqueue(int x){
		if(isEmpty()){
			back = front = new ListNode(x);
		}else{
			back = back->next = new ListNode(x);
		}
		size++;
	}
	
	int IntQueue::dequeue(){
		int frontItem = getFront();
		ListNode* old = front;
		front = front->next;
		
		if(size == 1){
			back = NULL;
		}
		delete old;
		size--;
		return frontItem;
	}
	
	
	exampleQueueMain.cpp
	----------------
	#include <iostream>
	#include "queue.h"
	
	int main(){
		IntQueue q; //initialized on the stack
		IntQueue r;
		
		IntQueue* p = new IntQueue(); //on heap
		
		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);
		q.enqueue(4);
		
		r=q; 			//copies all nodes from q to r, deep copy
		r.dequeue(); 	//r now has 234 q has 1234
		
		*p = r; 			//p now is the same as r
		p->enqueue(10);		//p is now 2 3 4 10
		
		q.printqueue();
	}
	```
	
	
	delete array on heap
	```
	int* p = new int[10];
	delete []p;
	```
		
		
- friends
	- how to fix the public ListNode
	- friend keyword can give access to restricted parts of classes (objects) to other classes/methods
	```c++
	class ListNode{
		private:
			int element;
			ListNode next;
			ListNode(_____):______{_____}
			
			friend class IntQueue;	//IntQueue class can access private member vairables and methods
			
			//or
			
			friend IntQueue::makeEmpty();	//IntQueue has acces to just this private method	
	};
	```
- nested classes
	- similar to java's inner (nested) classes
	- they work a lot like static nested classes in java
	- unlike java
		- private member variables in the nested classes are NOT visible to the enclosing class 
- static methods
	- java: `Math.sqrt`
	- C++: `Math::sqrt`
- static variables
	- java: `private static int boxCount=0;`
		- one variable for the entire class, not individual objects
	- C++: `private: static int boxCount;`
		- must be initialized outside of the class definition
		- in the .cpp file or later in the .h file outside the class definition
- inheritance in C++
	- C++ no ploymorphism inside constructors
	```C++
	class A{
		public:
			A(){
				cout << "in A constructor" << endl;
				init();	//calls A init not B init
			}
			
			//have to specifiy that init can be overriden
			//with virtual key word
			virtual void init(){
				cout << "int A init" << endl;
			}
	};
	
	class B{
		public:
			b(){
				cout << "in B constructor" << endl;
			}
			
			void init(){
				A::init();
				cout << "in B init" endl;
			}
	};
	
	
	main(){
		B* b = new B();
		//output
		//In A constructor
		//In A init
		//In B constructor
		
	}
	```
	
- abstract method 
	`virtual void aMethod()=0;`
	
- virtual keyword
	- any subclass can override the method