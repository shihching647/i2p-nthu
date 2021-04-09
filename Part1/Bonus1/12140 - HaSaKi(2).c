/**
* 解法(二): 只紀錄一個prefix sum, 為couns_head
*
* ex:  str = "sssss", sub_str = "ss"
* couns_head[]    1 2 3 4 4
* str             s s s s s
*
* ->ans = counts_tail[r - strlen(sub_str) + 1] - counts_head[l - 1]
*
*  扣掉一個substr的長度 + 1 =
*  1.如果r為substr最後一個字母 -> 找到substr對應的第一個字母的位置(包含一個完整substr)
*  2.其他 -> 找到前一組substr(不包含一個完整substr
**/

#include <stdio.h>
#include <string.h>
#define N_MAX 1005


int main(void) {

    freopen("12140_sampleIn.txt", "r", stdin);

    char str[N_MAX];
    char substr[N_MAX];
    scanf("%s%s", str, substr);
    int str_len = strlen(str);
    int substr_len = strlen(substr);

    int counts_head[N_MAX] = {0};

    //用strncmp比較字串相等(需要保證str, substr不會超出範圍)
    for (int i = 0; i + substr_len <= str_len; i++) {
        if (strncmp(str + i, substr, substr_len) == 0)
            counts_head[i + 1] = counts_head[i] + 1;
        else
            counts_head[i + 1] = counts_head[i];
    }


    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (str_len < substr_len) printf("0\n");
        else printf("%d\n", counts_head[r - substr_len + 1] - counts_head[l - 1]);
    }
}
