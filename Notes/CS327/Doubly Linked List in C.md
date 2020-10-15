```C
DLL.h
----------------------------------------------

#ifndef DLL_H
	#define DLL_H
	#ifndef NULL
		#define NULL 0
	#endif

	typedef struct node_t NODE;
	typedef struct node_t* NODEPTR;

	struct node_t{
		NODEPTR prev;
		NODEPTR next;
		void* date;
	};

	typedef struct list_t LIST;
	typedef struct list_t* LISTPTR;

	struct list_t{
		NODEPTR head;
		int numItems;
	};

	LISTPTR createList();
	int add(LISTPTR lst, void* item);
	void* get(LISTPTR lst, int index);
	void* rem(LISTPTR lst, int index);
	int emptyList(LISTPTR lst);
	void deleteList(LISTPTR lst);
#endif

```

```C
DLL.c
---------------------------------------------

#include <stdlib.h>
#include "DLL.h"

LISTPTR createList(){
	LISTPTR toReturn = malloc(sizeof(LIST));
	if(toReturn == NULL) return NULL;
	
	//init list, create dummy node and set numItems = 0
	toReturn->head = malloc(sizeof(NODE));
	if(toReturn-> == NULL){
		free(toReturn);
		return NULL;
	}
	//loops on itself
	toReturn->head->next = toReturn->head;
	toReturn->head->prev = toReturn->head;
	toReturn->head->data = (int*) 0x5555AAAA;	//everyother bit is flipped
	toReturn->numItems = 0;	
	
	return toReturn;
}

//append item onto the end of the list
int add(LISTPTR lst, void* item){
	NODEPTR p = malloc(sizeof(NODE));
	if(p == NULL) return NULL;
	
	p->date = item;
	
	//get last item
	NODEPTR lastNode = lst->head->prev;
	//assign last.next to the pointer to the new node
	last->next = p;
	
	//set p's pointers
	p->prev = lastNode;
	p->next = lst->head;
	lst->head->prev = p;
	
	lst->numItems++;
	
	return 1;
}

```


after workiva interview:
```C
void* rem (LISTPTR lst, int index){
	if((index < 0) || (index >= lst -> numItems)){
		return NULL;
	}
	NODEPTR p;
	int i;
	for(p=lst->head->next, i=0; i<index;i++,p=p->next);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	void* removed_data = p->data;
	free(p);
	lst->numItems -= 1;
	return removed_data;
}

//is the list empty?
int emptyList(LISTPTR lst){
	return lst->numItems == 0;
}

//remove all nodes to avoid memory leaks
void deleteList(LISTPTR lst){
	NODEPTR p = lst -> head;
	for(int i=0; i<lst->numItems + 1; i++){
		//temp variable to store the next pointer
		NODEPTR next = p->next;
		free(p);
		//set the next pointer to delete to the temp pointer
		p=next;
	}
	//free the memory for the list structure
	free(lst);
}
```

```C
main.c
-----------------------------
#include <stdio.h>
...

void printList(LISTPTR lst){
	for(int i=0; i<lst->numItems; i++){
		printf("%d\n",*(int *)get(lst, i));
	}
	printf("-------\n");
}

int main(int argc, char**argv){
	LISTPTR q = createList();
	int a = 5;
	int b = 6;
	int c = 8;
	add(q, &a);
	add(q, &b);
	printf("empty = %d\n", emptyList(q));
	printList(q);
	printf("get(0) = %d\n", *(int*) get(lst,0));
	while(rem(q,0)!= NULL);
	printf("empty = %d\n", emptyList(q));
}
```