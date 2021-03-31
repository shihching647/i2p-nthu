/**
 重點提示：
  任意選k個人, 只要是比m早選, 第哪幾個人是無所謂的.
  例如： 順位為4,你能指定1個人, 而這個人是第1,2或3結果都是一樣的
 */
#include <stdio.h>
#include <limits.h>

int a[5001];

void test_case(void);
int min(int, int);
int max(int, int);

int main(void) {
    freopen("12661_sampleIn.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        test_case();
    }
}

void test_case() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    //如果可操控的人數k比順位還m大, 只需嘗試到 m - 1就可以
    if (k >= m)
        k = m - 1;
    
    int ans = 0;
    for (int i = 0; i <= k; i++) { //控制前面k個人情況窮舉出來
        int front = 1, tail = n;
        //i == 0代表, 0個人選前面k個人選後面
        front += i;
        tail -= (k - i);
        int temp = INT_MAX;
        for (int j = 0; j < m - k; j++) { //把隨機選的人窮舉出來
            int f = front + j;
            int t = tail - (m - k - j - 1);
            //f, t位置兩者會取大的, 所得到的答案在跟之前的答案取小的
            temp = min(max(a[f], a[t]), temp);
//            printf("temp = %d\n", temp);
        }
        ans = max(temp, ans);
    }
    
    printf("%d\n", ans);
}

int min(int num1, int num2) {
    if (num1 < num2) return num1;
    else return num2;
}

int max(int num1, int num2) {
    if (num1 < num2) return num2;
    else return num1;
}
