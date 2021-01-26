//用 for 迴圈一一列出 1 到 100 每個數字的立方。

#include <stdio.h>

int main(void) {
    for(int i = 1; i <= 100; i++) {
        printf("%d\t",i * i * i);
    }
    return 0;
}
