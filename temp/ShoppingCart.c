#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart){
   cart.cartItems[cart.cartSize]=item;
   cart.cartSize++;
   return cart;
}

ShoppingCart RemoveItem(char name[], ShoppingCart cart){
   for(int i=0; i<cart.cartSize; i++){
      if (strcmp(cart.cartItems[i].itemName, name) == 0){
         for (int k=i; k<cart.cartSize-1; k++){
            cart.cartItems[k]=cart.cartItems[k+1];   
         }
         cart.cartSize--;
         return cart;
      }
   }
   printf("Item not found in cart. Nothing removed.\n");
   return cart;
}
ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart){
   for(int i=0; i<cart.cartSize; i++){
      if(strcmp(cart.cartItems[i].itemName, item.itemName) == 0){
         strcpy(item.itemDescription, cart.cartItems[i].itemDescription);
         item.itemPrice = cart.cartItems[i].itemPrice;
         cart.cartItems[i] = item;
         return cart;
      }
   }
   printf("Item not found in cart. Nothing modified.\n");
   return cart;
}

int GetNumItemsInCart(ShoppingCart cart){
   int sum = 0;
   for(int i=0; i<cart.cartSize; i++){
      sum += cart.cartItems[i].itemQuantity;
   }
   return sum;
}

int GetCostOfCart(ShoppingCart cart){
   int sum = 0;
   for(int i=0; i<cart.cartSize; i++){
      sum += cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice;
   }
   return sum;
}

void PrintTotal(ShoppingCart cart){
   printf("%s's Shopping Cart - %s\n",cart.customerName, cart.currentDate);
   printf("Number of Items: %d\n", GetNumItemsInCart(cart));
   printf("\n");

   if(GetNumItemsInCart(cart) == 0){
      printf("SHOPPING CART IS EMPTY\n");
      printf("\n");;
   }else{
      for(int i=0; i<cart.cartSize; i++){
         PrintItemCost(&(cart.cartItems[i]));
      }
      printf("\n");
   }
   printf("Total: $%d\n", GetCostOfCart(cart));
   printf("\n");

}

void PrintDescriptions(ShoppingCart cart){
if(cart.cartSize == 0){
      printf("SHOPPING CART IS EMPTY\n");
      return;
   }
   printf("%s's Shopping Cart - %s\n",cart.customerName, cart.currentDate);
   printf("Number of Items: %d\n", GetNumItemsInCart(cart));
   printf("\n");
   printf("Item Descriptions\n");
   for(int i=0; i<cart.cartSize; i++){
      PrintItemDescription(&(cart.cartItems[i]));
   }
}