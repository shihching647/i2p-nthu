#include <stdio.h>

int main111(void)
{
    int l, r;

    scanf("%d%d", &l, &r);
    if(l > r) {
        int temp = l;
        l = r;
        r = temp;
    }
    if(2 * l <= r)
        printf("%d %d\n", l ,2 * l);
}
