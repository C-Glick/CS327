#include <stdlib.h>
#include "DLL.h"

//create the list, makes a head node with unique data 0x5555AAAA
//returns a pointer to the list (LISTPTR)
LISTPTR createList(){
    LISTPTR toReturn = malloc(sizeof(LIST));
    if(toReturn == NULL) return NULL;
    
    //init list, create dummy node and set numItems = 0
    toReturn->head = malloc(sizeof(NODE));
    if(toReturn->head == NULL){
        free(toReturn);
        return NULL;
    }
    //loops on itself
    toReturn->head->next = toReturn->head;
    toReturn->head->prev = toReturn->head;
    toReturn->head->data = (int*) 0x5555AAAA;   //everyother bit is flipped unique value
    toReturn->numItems = 0; 
    
    return toReturn;
}

//append item onto the end of the list
//returns 1 if successful, 0 if failure
int add(LISTPTR list, void* item){
    NODEPTR p = malloc(sizeof(NODE));
    if(p == NULL) return 0;
    
    p->data = item;
    
    //get last item
    NODEPTR lastNode = list->head->prev;
    //assign last.next to the pointer to the new node
    lastNode->next = p;
    
    //set p's pointers
    p->prev = lastNode;
    p->next = list->head;
    list->head->prev = p;
    
    list->numItems++;
    
    return 1;
}

//returns a void pointer to the data at the 
//specified index, if out of range of the list
//returns null
void* get(LISTPTR list, int index){
    if(list->numItems <= index || index < 0){
        return NULL;
    }

    NODEPTR p = list->head->next;
    for(int i=0; i < index; i++){
        p = p->next;
    }
    return p->data;
}

//remove an item in the list at the specified index
//returns a void pointer to the data that was in that node
void* rem (LISTPTR list, int index){
    if((index < 0) || (index >= list->numItems)){
        return NULL;
    }
    NODEPTR p;
    int i;

    for(p=list->head->next, i=0; i<index;i++,p=p->next);
    
    p->prev->next = p->next;
    p->next->prev = p->prev;

    void* removedData = p->data;

    free(p);
    list->numItems -= 1;
    return removedData;
}

//returns true if the list is empty
//false otherwise
int emptyList(LISTPTR list){
    return list->numItems == 0;
}

//deletes the list structure, freeing the nodes before
//the entire list to avoid memory leaks.
//does not free the data pointers in the nodes.
void deleteList(LISTPTR list){
    NODEPTR p = list -> head;
    //frees all nodes including head
    for(int i=0; i <= list->numItems; i++){
        //temp variable to store the next pointer
        NODEPTR next = p->next;
        free(p);
        //set the next pointer to delete to the temp pointer
        p=next;
    }
    //free the memory for the list structure
    free(list);
}

//swap the two given indexes in the given list
void swap(LISTPTR list, int index1, int index2){
    if(index1 < 0 || index1 >= list->numItems || index2 < 0 || index2 >= list->numItems){
        fprintf(stderr, "sort error: swap index out of bounds");
        return;
    } 

    if(index1 == index2){
        return;
    }


    NODEPTR node1 = list->head->next;
    for(int i=0; i < index1; i++){
        node1 = node1->next;
    }

    NODEPTR node2 = list->head->next;
    for(int i=0; i < index2; i++){
        node2 = node2->next;
    }

    //swap data in the nodes
    void* tempdata = node1->data;
    node1->data = node2->data;
    node2->data = tempdata;
}

//print the given list to standard out, data is assumed
//to be string pointers each node
void printListStrings(LISTPTR list){
    printf("--------\n");
    for(int i=0; i < list->numItems; i++){
        printf("%s\n",(char *)get(list, i));
    }
    printf("--------\n");
}

//print the given list to standard out, data is assumed
//to be int pointers each node
void printListInts(LISTPTR list){
    printf("--------\n");
    for(int i=0; i < list->numItems; i++){
        printf("%d\n",*(int *)get(list, i));
    }
    printf("--------\n");
}

//print the given list to standard out, data is assumed
//to be int pointers each node
void printListFloats(LISTPTR list){
    printf("--------\n");
    for(int i=0; i < list->numItems; i++){
        printf("%f\n",*(float *)get(list, i));
    }
    printf("--------\n");
}