#include <stdio.h>
#include <string.h>

int counts[1000001]; //紀錄第i個數字之前1出現的總次數
int max_input = 1;   //目前計算到counts的數字

void update_counts(int upper_limit);

int main(void) {
    freopen("12678_sampleIn.txt", "r", stdin);
    int n, l, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        if (r >= max_input) { //如果r >= max_input (注意要>=, 非>) 更新counts陣列
            update_counts(r);
        }
//        printf("r = %d, l = %d\n", r, l);
        printf("%d\n", counts[r] - counts[l - 1]);
    }
    return 0;
}

void update_counts(int upper_limit) {
    char buf[8];
    int i = 0;
    while (upper_limit >= max_input) {
        //計算該數字有幾個1
        sprintf(buf, "%d", max_input); //將int -> cahr[]
//        printf("%s\n", buf);
        int count = 0;
        for (i = 0; i < strlen(buf); i++) {
            if (buf[i] == '1') count++;
        }
//        printf("count = %d\n", count);
        counts[max_input] = counts[max_input - 1] + count;
//        printf("count[%d] = %d\n", max_input, counts[max_input]);
        max_input++;
    }
}
