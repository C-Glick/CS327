#Structs

- a simple data structure
```c
struct point{
	int x;
	int y;
};
```
^ declares structure but does not allocate space for variables
```c
struct point{
	int x;
	int y;
} p1, p2, p3;
```
^declares structure and allocates space for p1, p2, and p3
`typedef struct point_ Point;`
^renames struct point to just Point

- unlike java, structs are not references, they are pass by value
- `p1=p2;` is a deep copy


- can use the "." selector (dot operator) to access components of an allocated struct
- `printf("%d, %d\n", maxpoint.x, maxpoint.y)`


## Structure pointer
- `struct point * ppoint`
	- pointer tha points to a structure 
- `*ppoint dereferences pointerPntr to a struct`
	- have to use parens because the . operator expects a struct! 
	- `(*ppoint).x` gives x component  of structure point
	- `ppoint -> x == (*ppoint).x`
		- used only on pointers to structs


## rules about structures
- the only legal operations on structs are
	- copy (assignment) including parameter passing and return
	- taking an address
	- accessing members with "."
- arrays of structures work as you would expect
	- the structs values are store directly in the array, allocates all needed space immediately