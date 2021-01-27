#ifndef DLL_H
    #define DLL_H
    #include <stdio.h>
    #ifndef NULL
        #define NULL 0
    #endif

    typedef struct node_t NODE;
    typedef struct node_t* NODEPTR;

    struct node_t{
        NODEPTR prev;
        NODEPTR next;
        void* data;
    };

    typedef struct list_t LIST;
    typedef struct list_t* LISTPTR;

    struct list_t{
        NODEPTR head;
        int numItems;
    };

    LISTPTR createList();
    int add(LISTPTR list, void* item);
    void* get(LISTPTR list, int index);
    void* rem(LISTPTR list, int index);
    int emptyList(LISTPTR list);
    void deleteList(LISTPTR list);
    void swap(LISTPTR list, int index1, int index2);
    void printListStrings(LISTPTR list);
    void printListInts(LISTPTR list);
    void printListFloats(LISTPTR list);

#endif