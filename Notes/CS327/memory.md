- stack
	- grows down from the top (incrementing memory address)
	- holds local variables, function parameters and return address
- heap
	- grow up from the bottom
	- can allocate memory and it returns a pointer
	- stays around between function calls and even after your program ends
- sizeof(\<type>)
	- returns the number of bytes used when storing a \<type> variable
- malloc
	- in stdlib.h
	- void* malloc(int size);
	- size is in bytes
	- says "I want *size* bytes from heap memory"
	- returns a pointer to that memory or NULL if it could not allocate the memory
	- void pointer can be assigned to any other pointer type, no cast required
	- ex:
		- int* p = malloc(sizeof(int));
	- memory leak
		- can call malloc on the same pointer multiple times
			- causes issues because the old memory address is still in use but is no longer referenceable  
		- using malloc inside a function, then return the function without freeing the heap memory
- calloc
	- in stdlib.h
- free
	- free(pointer to memory to free);
	- #Structs 
	- ![[Pasted image 20200922130609.png]]