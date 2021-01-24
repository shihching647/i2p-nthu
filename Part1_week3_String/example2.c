//
//  example2.c
//  i2p-nthu
//
//  Created by 劉仕卿 on 2021/1/16.
//

#include <stdio.h>
#define ENGINE 1499.99
int main_w3_2(void)
{
   printf("~%f~\n", ENGINE); //預設到小數點第6位
   printf("~%e~\n", ENGINE);
   printf("~%4.2f~\n", ENGINE);
   printf("~%3.1f~\n", ENGINE);
   printf("~%10.3f~\n", ENGINE); //10.3f,` 10代表總長度不超過10時要在前面補空白
   printf("~%-10.3f~\n", ENGINE); //-10.3f, 10代表總長度不超過10時要在後面補空白
   printf("~%12.3e~\n", ENGINE);
   printf("~%+4.2f~\n", ENGINE);
   printf("~%010.2f~\n", ENGINE); //010.2f, 前面0代表總長度不超過10時要在前面補0
   return 0;
}
