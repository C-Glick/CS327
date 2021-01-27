#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart cart);

int main(void) {
   ShoppingCart cart;
   cart.cartSize=0;
   
   printf("Enter Customer's Name:\n");
   fgets(cart.customerName, 50, stdin);
   strtok(cart.customerName, "\n");
   
   printf("Enter Today's Date:\n");
   fgets(cart.currentDate, 50, stdin);
   strtok(cart.currentDate, "\n");
   
   printf("\n");
   printf("Customer Name: %s\n", cart.customerName);
   printf("Today's Date: %s\n", cart.currentDate);
   printf("\n");
   
   PrintMenu(cart);
   
   return 0;
}

void PrintMenu(ShoppingCart cart){
   int loop = 1;
   
   while(loop){
      printf("MENU\n");
      printf("a - Add item to cart\n");
      printf("r - Remove item from cart\n");
      printf("c - Change item quantity\n");
      printf("i - Output items' descriptions\n");
      printf("o - Output shopping cart\n");
      printf("q - Quit\n");
      printf("\n");
      printf("Choose an option:\n");
      
      char input[10];
      fgets(input, 10, stdin);
      strtok(input, "\n");

      while(input[0]!='a'&&input[0]!='r'&&input[0]!='c'&&input[0]!='i'&&input[0]!='o'&&input[0]!='q'){
         if(input[0] != '\n'){
            printf("Choose an option:\n");
         }
         fgets(input, 10, stdin);
         strtok(input, "\n");
      }
      switch (input[0]){
         case 'a':
            printf("ADD ITEM TO CART\n");
            ItemToPurchase item;
            MakeItemBlank(&item);
            printf("Enter the item name:\n");
            fgets(item.itemName, 50, stdin);
            strtok(item.itemName, "\n");
            
            printf("Enter the item description:\n");
            fgets(item.itemDescription, 100, stdin);
            strtok(item.itemDescription, "\n");
            
            printf("Enter the item price:\n");
            fgets(input, 10, stdin);
            strtok(input, "\n");
            item.itemPrice = atoi(input);
            //scanf("%d", &(item.itemPrice));
            
            printf("Enter the item quantity:\n");
            fgets(input, 10, stdin);
            strtok(input, "\n");
            item.itemQuantity = atoi(input);
            //scanf("%d",&(item.itemQuantity));
            
            cart = AddItem(item, cart);
            
            printf("\n");
            break;
         case 'r':
            printf("REMOVE ITEM FROM CART\n");
            printf("Enter name of item to remove:\n");
            char temp[50];
            fgets(temp, 50, stdin);
            strtok(temp, "\n");
            cart = RemoveItem(temp, cart);
            printf("\n");
            break;
         case 'c':
            printf("CHANGE ITEM QUANTITY\n");
            ItemToPurchase changeItem;
            MakeItemBlank(&changeItem);
            printf("Enter the item name:\n");
            fgets(changeItem.itemName, 50, stdin);
            strtok(changeItem.itemName, "\n");
            
            printf("Enter the new quantity:\n");
            fgets(input, 10, stdin);
            strtok(input, "\n");
            changeItem.itemQuantity = atoi(input);
            //scanf("%d",&(changeItem.itemQuantity));
            
            
            cart = ModifyItem(changeItem, cart);
            printf("\n");
            break;
         case 'i':
            printf("OUTPUT ITEMS' DESCRIPTIONS\n");
            PrintDescriptions(cart);
            break;
         case 'o':
            printf("OUTPUT SHOPPING CART\n");
            PrintTotal(cart);
            break;
         case 'q':
            loop=0;
            break;
         default:
            break;
      }
   }
}