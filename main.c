#include<stdio.h>
#include "header.h"
int main()
{
 printf("Inside main\n"); 
 printf("Calling hello function\n");
 hello();
 printf("Calling add function\n");
 add(10,20);
 printf("Back to main\n");
 return 0;
}
