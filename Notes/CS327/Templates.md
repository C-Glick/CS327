- c++ templates (generics for c++)
	- templates are Turing complete
	- can do computations in only templates, very complicated
	- the template can have any type including primitive types, 
		- int float* double, etc
	- implementing a class template
	```cpp
	//.h file-------------------
	
	template <class T> 
	class Stack{
		public:
			Stack(int = 10);
			~Stack{delete [] stackptr;}
			int push(const T&);
			int pop(T&);
			int isempty() const {return top == -1;}
			int isFull() const {return top == size-1;}
		private:
			int size;
			int top
			T* stackprt;
	};
	```
	
	```cpp
	//B.h
	template <class T>
	class B{
		public:
			....
	}
	
	//B.cpp-----------------
	#include "B.h"
	template <class T>
	B<T>::B(){
	}
	
	template <class T>
	B<T>::~B(){
	
	}
	
	template <class T>
	int B<T>::foo(){
		return 1;
	}
	
	//main.cpp------------------
	#include "B.h"
	void main(){
		B<int> bi;
		B<float*> bfp;
		B<float*>* p = new (B<float*>);
	}