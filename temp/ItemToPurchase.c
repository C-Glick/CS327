#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"

/* Type your code here */
void MakeItemBlank(ItemToPurchase* item){
   strcpy(item->itemName, "none");
   strcpy(item->itemDescription, "none");
   item->itemPrice = 0;
   item->itemQuantity = 0;
}
void PrintItemCost(ItemToPurchase* item){
   printf("%s %d @ $%d = $%d\n", item->itemName, item->itemQuantity, item->itemPrice, item->itemQuantity * item->itemPrice);
}

void PrintItemDescription(ItemToPurchase* item){
   printf("%s\n", item->itemDescription);
}