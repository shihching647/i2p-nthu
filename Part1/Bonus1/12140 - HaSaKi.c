/**
* 解法(一): 紀錄兩個prefix sum, 分別為couns_head, counts_tail
*
* ex:  str = "sssss", sub_str = "ss"
* couns_head[]    1 2 3 4 4
* str             s s s s s
* counts_tail[]   0 1 2 3 4
*
* ->ans = counts_tail[r] - counts_head[l - 1]
**/
#include <stdio.h>
#include <string.h>
#define N_MAX 1001

int check_head(int);
int check_tail(int);
char str[N_MAX];
int str_size;
char sub_str[N_MAX];
int sub_str_size;

int main(void) {

    freopen("12140_sampleIn.txt", "r", stdin);

    scanf("%s%s", str, sub_str);
    str_size = strlen(str);
    sub_str_size = strlen(sub_str);
    int counts_head[N_MAX] = {0};
    int counts_tail[N_MAX] = {0};

    for (int i = 0; i < str_size; i++) {
        counts_head[i + 1] = check_head(i) + counts_head[i];
        //printf("%d, ", counts_head[i]);
    }

    //printf("\n");

    for (int i = 0; i < str_size; i++) {
        counts_tail[i + 1] = check_tail(i) + counts_tail[i];
        //printf("%d, ", counts_tail[i]);
    }

    //printf("\n");
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", counts_tail[r] - counts_head[l - 1]);
    }
    return 0;
}

int check_head(int n) {
    for (int i = 0; i < sub_str_size; i++) {
        if (str[i + n] != sub_str[i] || i + n >= str_size) //i + n >= str_size代表超過str範圍
            return 0;
    }
    return 1;
}

int check_tail(int n) {
    for (int i = 0; i < sub_str_size; i++) {
        if (str[n - i] != sub_str[sub_str_size - i - 1] ||  n - i < 0) //n- i < 0代表超過str範圍
            return 0;
    }
    return 1;
}
