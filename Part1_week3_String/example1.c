//
//  example1.c
//  i2p-nthu
//
//  Created by 劉仕卿 on 2021/1/16.
//

#include <stdio.h>
#include <string.h>
#define SPEED 0.083

int main_w3_1(void)
{
   float minutes, distance;
   int size;
   unsigned long letters;
   char name[10]; /* character array, string */

   printf("Hi! What's your first name? ");
   scanf("%9s", name );
   printf("\n%s, how many minutes does it take to walk from\n", name);
   printf("your dormitory to the Delta building? ");
   scanf("%f", &minutes);
   size = sizeof(name);
   letters = strlen(name);

   distance = minutes * SPEED;
    printf("%f\n", minutes);
   printf("\nThe distance from your dormitory to the Delta building\n");
   printf("is about %.3f kilometers.\n\n", distance);
  
   printf("By the way, your first name has %ld letters,\n", letters);
   printf("and we have %d bytes to store it in.\n", size);

   return 0;
}
