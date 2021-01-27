- issues
	- forgetting to allocate and then using a pointer 
	- forgetting to delete a heap object
	- use object after it has been deleted
	- invoking delete twice on the same object
- ways to help avoid problems in c++
	- only have one reference/pointer to a heap object value
		- not practical, and you can still have a memory leak
	- use a reference count 
		- keep track of number of pointers/references to the object
	- garbage collectors
## general concepts
- an individual allocated piece of data is called a **node**, **cell**, or **object** 
- need to define the root pointers or root references to be all nodes that are referenced by a pointer on the stack, in a register, in global memory, etc.
- the pointer reachability relation tells us if an object/node on the heap is reachable from a root pointer, or a chain of pointers staring with any root pointer
- an object is **live** if the pointer reachability relation is true
	- for any node M (or root reference) and some other node N
		- M is related to N (written m -> n) if and only if there is a pointer in M that points to N
- the set of live nodes in a heap is the **transitive referential closure**  of the set of root references under the -> relation
	- live is the least set, `live = {N ε Nodes | fr ε roots r ->N or fm ε live M->N}`
		- all possible nodes, add all things that can be reach from any root pointer into the live step
		- start with all root pointers in live, look at all pointers in each object in live, if its not currently in live, add it to live
		- repeat until live doesn't change anymore
- Note that the set live is conservative and may include more objects than your program can currently get access to 
	- local variable that contains a pointer after the variable is no longer used
	- an uninitialized variable on the stack happens to point (accidentally) to a memory node
	- an obsolete reference or pointer to a object left in a register
- A nodes "liveness" property may be determined directly or indirectly 
	- direct methods require that a record be associated with each node's references to it
		- reference counting
	- indirect methods regenerate the set of live objects/nodes whenever a request by the user program for more memory fails
- creating garbage
	- replace a node in a link list that points to a new list
	- break pointers within freeing memory
- why garbage collect?
	- in OO languages it is very often desirable to return objects
	- from methods/functions
	- if you have functions that return objects, "who" is responsible or making sure the object is deleted?
		- thats why garbage collectors are made
- some notation
	- the heap is a contiguous array of words, organized into discontinuous blocks of words
	- the heap is made of cells / nodes / objects, assumed to be a contiguous array of bytes/words divided into fields
	- object / cell / node that contains no pointer field is called an **atom**
	- the data in the heap reachable from the root pointers (live set) forms a directed graph defined by the -> relation.
## reference counting
- the method keeps track if cells are in use by counting the references in each cell
- each cell has an additional field called "referenceCount"
- for simplicity, assume all cells are stored in a pool of free cells
- the free pool is implemented as a linked list with the next field pointing to the next free cell
	- the next field often placed in the same memory location as the reference count since they are never needed at the same time
- allocation algorithm
	```c
	struct cell{
		char memory[SIZE];
		union{
			cell* next;
			int rc;
		}admin;
	}
	
	strcut cell heap[HEAP_SIZE];
	struct cell* freeList = heap;
	void initalizeHeap(){
		for(int i = 0; i<HEAP_SIZE -1; i++){
			heap[i].admin.next = &heap[i+1];
		}
		heap[HEAP_SIZE-1].admin.next=NULL;
	}
	
	void* new(){
		if(free_list == NULL){
			//ERROR no space available
		}
		//head of free_list
		cell* newcell = free_list;
		free_list = free_list->admin.next; //first cell in the list is no longer in the list, change the head location
		
		newcell->admin.rc = 1;	//change admin to the reference counter instead of a pointer to next
		
		return (void*)newcell;
	}
	
	//put the cell back in the free list if there are no more references to it
	void delete(void* p){
		cell *cp = (cell*) p;
		
		//first delete any pointers inside the cell to be deleted
		foreach pointer u in *cp
		{
			delete pointer(u);
		}
		
		cp->admin.rc -= 1;
		if(cp->admin.rc == 0){
			cp->admin.next = free_list;
			free_list = cp;
		}
	}
	
	//update the pointer that is held in a cell to another cell
	
	void update(void** R, void* s){	//*R is pointer to change, *S is what it will be changed to
		delete(*R);
		
		*R = s;
		//increment the rc of the new pointer
		((cell*)s)->admin.rc += 1;
	}
	```
	![[Pasted image 20201112131004.png]]
	



---------------
## more garbage collection
- mark and sweep algorithm
	- McCarthy in 1960
	- cells are not reclaimed immediately but rather remain "used" in memory until collected
	- if there is a request for new memory and there is no memory available for immediate allocation. then processing is suspended while the garbage collector is called to sweep all currently unused cells from the heap back to the pool of free cells
		- program would run for a while then freeze for a second
		- undesirable
		- changed to incremental garbage collection
	- relies on the traversal of all the live objects on the heap to identify what should not be returned to the free pool uses depth first or breadth first search
	- after items are traversed and marked as reachable (mark stage), the algorithm removes all items that are not marked (the sweep stage)
	- pseudo code for algorithm
		```
		void* new(){
			if(free_pool == null){
				mark_sweep();
			}
			newCell = allocate();
			return newCell;
		}
		
		void mark_sweep(){
			//for each root pointer
			for(R in roots){
				//mark R and all things under R
				mark(R);
			}
			sweep();
			if(free_pool == null){
				throw out of memory error
			}
		}
		
		//assume each chunk of memory that we can 
		//allocate has a special bit used to mark the memory
		void mark(N){
			if(N->markbit == UNMARKED){
				N->markbit = MARKED;
				for each pointer reference M in N{
					mark(M);
				}
			}			
		}
		
		//iterate through heap, checking the mark bit
		void sweep(){
			N = heap_bottom;
			while(N < heap_top){
				if(N->markbit == UNMARKED){
					free(N);
				}else{
					N->markbit = UNMARKED;
				}
				N += sizeof(N);
			}
		}
		```
		
		- copying garbage collection
			- keeps combining things together to keep the memory from fragmenting, keeps things contiguous 