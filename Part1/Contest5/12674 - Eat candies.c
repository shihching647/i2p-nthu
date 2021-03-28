#include <stdio.h>
#include <stdlib.h>

int minimum (int, int);

int main(void) {
    freopen("12674_sampleIn.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int r, g, b;
    int candy[3];
    for (int i = 0; i < n; i++) {
        //用insertion sort 將 r,g,b 由小排到大
        scanf("%d %d %d", &r, &g, &b);
        candy[0] = r;
        if (g > candy[0]) {
            candy[1] = g;
        } else {
            candy[1] = candy[0];
            candy[0] = g;
        }
        if (b > candy[1]) {
            candy[2] = b;
        } else if (b > candy[0]) {
            candy[2] = candy[1];
            candy[1] = b;
        } else {
            candy[2] = candy[1];
            candy[1] = candy[0];
            candy[0] = b;
        }
//        printf("%d %d %d     ", candy[0], candy[1], candy[2]);
        
        //概念: 先吃最少的, 但要維持另外兩個越平均越好, 但是中間數也可能小於平均值, 若是此情況下,取中間數
        //ans = 小 + minimum((中 + 大 - 小) / 2, 中)
        printf("%d\n", candy[0] + minimum((candy[1] + candy[2] - candy[0]) / 2, candy[1]));
    }
    return 0;
}

int minimum(int num1, int num2) {
    if (num1 > num2) return num2;
    else return num1;
}

