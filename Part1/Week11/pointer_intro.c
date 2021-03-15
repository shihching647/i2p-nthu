#include <stdio.h>

typedef int *int_ptr; //可用typedef定義指標type, 就可一次宣告多個指標變數

int main(void) {
    int_ptr p1, p2, p3; //一次告多個指標變數
    int *ptrx, *ptrx2; //或是這樣也可以
    double *ptry;
    int x = 1;
    double y = 1.1;
    
    //若沒初始化, 會造成程式當機
    ptrx = &x;
    ptry = &y;
    p1 = &x;
    
    printf("%p %p\n", ptrx, ptry);
    printf("%lu %lu\n", sizeof(ptrx), sizeof(ptry));
    printf("%lu %lu\n", sizeof(x), sizeof(y));
    printf("%d %f\n", *ptrx, *ptry);
}
