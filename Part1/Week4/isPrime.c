/*
輸入一個正整數
程式必須列出除了 1 和該正整數本身以外的全部因數
因數必須從小到大排列
如果無法因數分解
則成是必須顯示這個正整數是質數
*/
#include <stdio.h>
int main(void)
{
   int num = 0, div;
   int isPrime = 1;

   printf("Please enter an integer (q to quit): \n");

   scanf("%d", &num);
   if (num == 0) return 0;

   for (int i = 2; i < num; i++) {
	   if (num % i == 0) {
		   isPrime = 0;
		   printf("%d  ", i);
	   }
   }

   if (isPrime)
      printf("%d is prime.\n", num);
   else
      printf("\b\b are divisors of %d\n", num);

   return 0;
}
