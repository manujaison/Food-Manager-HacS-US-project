#include<stdio.h>
#include<string.h>
struct food {
  char mat[20];
  float quantity;
} item[50];
void main() {
  char op,str[20];
  int i=0,num=0;
  float used;
  printf("Welcome to Food Manager,");
  printf("\nEnter the number of items purchased: ");
  scanf(" %d",&num);
  for(i=0; i<num; i++) {
    fflush(stdin);
    printf("Enter item: ");
    gets(item[i].mat);
    printf("Enter quantity(in kg): ");
    scanf(" %f",&item[i].quantity);
  }
  printf("\nThe products you have are :");
  printf("\n	ITEM   QUANTITY(in kg)");
  for(i=0; i<num; i++) {
    printf("\n	%s : %f",item[i].mat,item[i].quantity);
  }
y:
  fflush(stdin);
  printf("\nEnter the name of item you wish to use: ");
  gets(str);
  for(i=0; i<num; i++) {
    if(strcmp(str,item[i].mat)==0) {
      if(item[i].quantity>=1) {
        printf("\nEnter the quantity(in kg): ");
        scanf(" %f",&used);
        if(item[i].quantity>=used) {
          item[i].quantity=item[i].quantity-used;
          fflush(stdin);
        } else
          printf("Not enough left!!!");
        break;
      } else {
        printf("\nItem not in stock!!");
        break;
      }
    } else
      printf("Item not in stock!!");

  }
  printf("\nThe products you have are :");
  printf("\n	ITEM   QUANTITY(in kg)");
  for(i=0; i<num; i++) {
    printf("\n	%s : %f",item[i].mat,item[i].quantity);
  }
  printf("\nDo you wish to use more items(y/n)?: ");
  scanf(" %c",&op);
  if(op=='y')
    goto y;
  printf("\nThe items left are: ");
  printf("\n	ITEM   QUANTITY(in kg)");
  for(i=0; i<num; i++) {
    printf("\n	%s : %f",item[i].mat,item[i].quantity);
  }
}