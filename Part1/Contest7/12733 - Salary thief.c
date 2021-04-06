/**
 解法：將字串長度與字串本身分開算
 1. (int)1E9 + 7 與 10000000007不一樣！！！
 2. 兩個大數相乘會超過long long的範圍, 需使用到(a * b) % MOD = ((a * MOD) - (b * MOD)) % MOD
 3. strlen(n) in O(n)
 */
#include <stdio.h>
#include <string.h>
#define N_MAX 10000000
#define MODLE_NUMBER 1000000007

void test_case(void);
char str[N_MAX];
char temp[N_MAX];

int main(void) {
    freopen("12733_sampleIn.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        test_case();
    }
    return 0;
}

void test_case() {
    int need_strcat = 1; //用來記錄是否需要strcat(長度是否已超過n)
    long long size;
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    size = strlen(str);
    for (int i = 0; i < n; i++) {
        int digit = str[i] - '0';
//        printf("digit = %d\n", digit);
        
        // (a + b) % MOD = ((a % MOD) + (b % MOD)) % MOD
        // (a - b) % MOD = ((a - MOD) - (b - MOD)) % MOD
        // (a * b) % MOD = ((a * MOD) - (b * MOD)) % MOD
        // 兩個大數相乘會超過long long的範圍
        //  新  =   舊   +      後半段       *  前半段最後一位數
        // size = 原size + (原size - i - 1) * (digit - 1)
        size += ((size - i - 1) % MODLE_NUMBER * (digit - 1) % MODLE_NUMBER) % MODLE_NUMBER;
//        printf("size = %lld\n", size);
        //檢查是否需要連接字串
        if (need_strcat && strlen(str) <= n) {
            strcpy(temp, str + i + 1); //temp = str.substring(i + 1, end)
//            printf("temp = %s\n", temp);
            for (int j = 0; j < digit - 1; j++) {
                strcat(str, temp);    //str += temp;
            }
        } else {
            need_strcat = 0;
        }
//        printf("%s\n============\n", str);
    }
    printf("%lld\n", size % MODLE_NUMBER);
}
