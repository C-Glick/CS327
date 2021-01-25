overloading operators
user operators are permitted only if one or both of the types is user defined
precedence and associative properties are fixed for the operator
![[Pasted image 20201105135158.png]]
operators can be defined in two ways
1) independent of class definition (use friend to get to private or protected members)
	- ![[Pasted image 20201105134741.png]]
2) method in the class
	- ![[Pasted image 20201105134914.png]]
- ![[Pasted image 20201105135428.png]]
	- the value of the int in the postfix version doesn't matter will be garbage in the function