/**
 換銅板問題：
 當我們有1元、5元、10元時，我們有哪些組合方法可以用這些錢幣湊出50元呢？

 換銅板就是解決這類的問題，用某些幣值組合出想要的數量。

 我們可以先盡量用越多最大幣值，再用小幣值補足剩下的餘額。
 將最大幣值的數量減一，餘額再用小幣值捕。
 以此類推，我們可以得到所有可能的組合。
 */
#include <stdio.h>
#define MAXNV 5

int values[MAXNV];
int numbers[MAXNV];

void show(int nv);
void change(int amount, int startNv, int endNv);
int count;

int main() {
    int nv, money;
    scanf("%d", &nv);
    if (nv > MAXNV || nv < 1) {
        printf("面額數量錯誤\n");
        return 0;
    }
    for (int i = 0; i < nv; i++) {
        scanf("%d", values + i);
    }
    scanf("%d", &money);
    change(money, 0, nv);
    printf("count = %d\n", count);
    return 0;
}

void show(int nv) {
    for (int i = 0; i < nv; i++) {
        if (i == 0) printf("(%d", numbers[i]);
        else printf(", %d", numbers[i]);
    }
    printf("\b)\n");
}

void change(int amount, int startv, int endNv) {
    //starNv >= endNv 表示沒有可換的面額
    if (startv < endNv) {
        if (amount == 0) { //amount = 0 -> 符合金額, 顯示出來
            show(endNv);
            count++;
        } else if (amount > 0) { //amount > 0 才需繼續換
            //1.金額不變少一個面額,下去換
            change(amount, startv + 1, endNv);
            //2.先用此面額換一枚,將剩下的錢用相同的面額下去換
            numbers[startv]++;//先換一枚
            change(amount - values[startv], startv, endNv);//遞迴呼叫
            numbers[startv]--;//換回一枚
        }
    }
}
