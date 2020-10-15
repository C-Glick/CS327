& right after a type creates a reference variable
- & = bitwise AND, n & m
- && = logical AND if(x > 1 && y < 10)
- & = address of operator, int * p = &j;
- & = references variable , int &j = i;
```c++
int i = 7;
int &j = i;	//j not is a reference to the variable i

j++;	//really i++
i+=3; 	
//both i and j now equals 11

```
