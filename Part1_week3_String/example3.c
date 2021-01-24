//
//  example3.c
//  i2p-nthu
//
//  Input: University
//  ############
//  #University#
//  ############

//  Created by 劉仕卿 on 2021/1/16.
//

#include <stdio.h>
#include <string.h>
#define BORDER "############################"

int main(void) {
    char word[26];
    scanf("%25s", word); //限制長度為25(留一格給\0)
    int length = (int) strlen(word);
    
    printf("%.*s\n", length + 2, BORDER);
    printf("#%s#\n", word);
    printf("%.*s\n", length + 2, BORDER);
    return 0;
}
