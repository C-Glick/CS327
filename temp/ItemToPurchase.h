#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

/* Type your code here */
typedef struct ItemToPurchase{
   char itemName[50];
   char itemDescription[100];
   int itemQuantity;
   int itemPrice;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase* item);
void PrintItemCost(ItemToPurchase* item);
void PrintItemDescription(ItemToPurchase* item);

#endif