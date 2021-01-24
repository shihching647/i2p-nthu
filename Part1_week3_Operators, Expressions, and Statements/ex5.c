//
//  ex5.c
//  i2p-nthu
//      A
//     AB
//    ABC
//   ABCD
//  ABCDE
//  Created by 劉仕卿 on 2021/1/17.
//

#include <stdio.h>
#include <string.h>
int main3_5(void)
{
   int i = 1, word_len;
   char word[40];
   scanf("%s", word);

   word_len = strlen(word);

   while (i <= word_len) {
      printf("%*.*s\n", word_len, i, word);
      i++;
   }

   return 0;
}
