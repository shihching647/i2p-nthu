/**
 Pointer example
 */

#include <stdio.h>

int main(void) {
    char data[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    char* p;
    int* q;
    long long *r;
    
    p = data;
    q = (int*) data;
    r = (long long*) data;
    
    printf("p address:\n");
    while (p < &data[16]) {
        printf("%p %d\n", p, *p);
        p++;
    }
    
    printf("q address:\n");
    while (q < (int*)&data[16]) {
        printf("%p %08x %d\n", q, *q, *q); //一次讀4個byte時, 最重要的位數會比較後面
        q++;
    }
    
    printf("r address:\n");
    while (r < (long long*)&data[16]) {
        printf("%p %lld %016llx\n", r, *r, *r); //一次讀8個byte時, 最重要的位數會比較後面
        r++;
    }
}
