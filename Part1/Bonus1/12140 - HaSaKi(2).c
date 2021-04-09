/**
* �Ѫk(�G): �u�����@��prefix sum, ��couns_head
*
* ex:  str = "sssss", sub_str = "ss"
* couns_head[]    1 2 3 4 4
* str             s s s s s
*
* ->ans = counts_tail[r - strlen(sub_str) + 1] - counts_head[l - 1]
*
*  �����@��substr������ + 1 =
*  1.�p�Gr��substr�̫�@�Ӧr�� -> ���substr�������Ĥ@�Ӧr������m(�]�t�@�ӧ���substr)
*  2.��L -> ���e�@��substr(���]�t�@�ӧ���substr
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

    //��strncmp����r��۵�(�ݭn�O��str, substr���|�W�X�d��)
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
