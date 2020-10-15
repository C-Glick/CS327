G++ is the compiler for C++, `g++ -c -g -o myfile.o myfile.cpp`
- file extensions
	- .h header files
	- .cpp source code
```C++
//hello world
#include <iostream>
using namespace std;
int main(){
	//cout = std::cout, but declared we are using std so not needed
	cout << "Hello World\n"; 	//left shift is overloaded to send the string
	return 0;
}
```

```C++
	cout << "someting";
	cout << 120;
	cout << x;
	
	//OR equal to
	
	cout << "something" << 120 << x;
```

`endl` prints new line and flushes the buffer
```c++
cout << "This is" << endl << "my test"
```

prints:
```
This is
my test
```


input object, cin
```c++
int age;
cin >> age;
```

```C++
#include <iostream>
using namespace std;

int main(){
	cout << "Enter age and zipcode";
	int age;
	int zipcode;
	cin >> age >> zipcode;
	return 0;
}
```


