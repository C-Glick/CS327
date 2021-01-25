think of it like an alias in Linux

& right after a type creates a reference variable
- & = bitwise AND, n & m
- && = logical AND if(x > 1 && y < 10)
- & = address of operator, int * p = &j;
- & = references variable , int &j = i;
```c++
int i = 7;
int& j = i;	//j not is a reference to the variable i

j++;	//really i++
i+=3; 	
//both i and j now equals 11

```
- rules of references
	- references can never be NULL
	- once established the reference can never be changed to a different object
	- a reference does not require any explicit mechanism to dereference, just use like a normal local variable
- can also pass parameters to functions by reference
	- ex
	```c++
	void passTest(int& i){	//pass by reference, actually changing the value passed in
		i++;
		i = 7;
	}
	
	int main (){
		int j = 5;
		passTest(j);
		cout << j << endl;	//outputs 7
		return 0;
	}
	```
	- a reference may be used as the target of an assignment statement
	- that means a function can return a reference to a variable
	```c++
	int value[100];
	int& index(int i){
		return values[i+2];
	}
	main(){
		index(27) = 12;	//assigns 12 to the 29th index of the array
	}
	```
	- operator overloading
	```c++
	class string{
		char& operator [] (unsigned int index){ //overloads []
			return buffer[index]
		}
	}
	
	String test = "asdfasdw";
	test[0] = 'f'; //test = "fsdfasdw"
	```
	- returning a reference is much more efficient than returning an entire object on the stack
		```c++
		Pair& minmax(double data[], int n){
			double minval = data[0];
			double maxval = data[0];
			
			for(int i=0; i<n; i++){
				if (data[i] < minval) minval = data[i];
				if (data[i] > maxval) maxval = data[i];
			}
			Pair p(minval, maxval);	//class Pair stores a pair of doubles
			return p;	//doesnt work becase we a returning a refernce (see function header)
		}
		```
		- types of common memory errors
			- Life time errors
				- once a method or function ends, the variables stored on the stack associated with that method/function call are no longer valid.
				- very typical error 
					```c++
					char* readAline(){
						char buffer[1000];
						gets(buffer);
						return buffer;
					}	//when readAline ends buffer is not valid anymore
					//usually correct but not guaranteed
					```
			- size errors	
				- size of objects have to be known and compile time
					- array sizes and stuff
				- can accidentally overwrite some data when going out of bounds
- pointers to objects in c++
	- objects are allocated on the heap
	- just as you would expect
	```c++
	Box* b;
	b = new Box(7);	//allocated on the heap
	Box b2 = *b; //copy constructor and put it on the stack
	print box(b2);