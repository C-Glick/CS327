#include <stdio.h>
#include "gensnd.h"

int main(){
    char number[10];
    printf("Enter a 10 digit number: ");
    for(int i=0; i<10; i++){
        scanf("%c", number+i);
        //verify valid character, if invalid re-enter
        switch(*(number+i)){
            case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case 'a': case 'b': case 'c':
            case 'd': case 'A': case 'B': case 'C': case 'D': case '*': case '#':
                continue;
            default:
                i--;
                continue; 
        }
    }

    for(int i=0; i<10; i++){
        buttonTone(number[i]);
        if(i!=9) silence(8000, 0.25);
    }

    return 0;
}