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
	text[0] = 'f';