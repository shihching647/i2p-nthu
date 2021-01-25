/*
How to print a Pascal Triangle?
Try it yourself.
0 0 0 0 0 0
0 1 0 0 0 0
0 1 1 0 0 0
0 1 2 1 0 0
0 1 3 3 1 0
0 1 4 6 4 1
...
*/

#include <stdio.h>

int main(void) {
    int i = 0, j;
    int a[10][10];

    while (i < 10) {
        j = 0;
        while (j < 10) {
            if(i == 0 || j == 0) a[i][j] = 0; //第一行跟第一列是0
            else if(j > i) a[i][j] = 0;  //右上半都是0
            else if(j == i) a[i][j] = 1; //對角線是1
            else a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            j++;
        }
        i++;
    }

    i = 0;
    while (i < 10) {
        j = 0;
        while(j < 10) {
            printf("%5d", a[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}

