#include <stdio.h>
#define MAX  1000000

int a[MAX];
int eaten[MAX]; //用來記錄西瓜是否被吃, 0 = 沒被吃, -1 = 已經被吃

int main(void) {
    freopen("12132_sampleIn.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        int no;
        scanf("%d", &no);
        int count = 0;
        if (eaten[no] == 0) {
            while (j == 0 || a[j - 1] != no) {
                eaten[a[j]] = -1;
                count++;
                j++;
            }
        }
        if (i != n - 1) printf("%d ", count);
        else printf("%d", count);
    }
    printf("\n");
}
