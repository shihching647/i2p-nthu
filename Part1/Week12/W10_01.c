/* W10_01.c */
#include <stdio.h>
#define MAX_SIZE 50
#define LOWER_LIMIT 0
#define UPPER_LIMIT 1000000
int main(void) {
    int data[MAX_SIZE];
    int i, j, size;
    int maxval=LOWER_LIMIT, minval=UPPER_LIMIT;
    freopen("test.txt", "r", stdin);
    for (size = 0; size < MAX_SIZE; size++) {
        if (scanf("%d", &data[size]) != 1)
            break;
    }
    for (i = 0, j= size - 1; i <= j; i++, j--) {
        if (data[i] > data[j]) {
            if (maxval < data[i]) maxval = data[i];
            if (minval > data[j]) minval = data[j];
        } else {
            if (minval > data[i]) minval = data[i];
            if (maxval < data[j]) maxval = data[j];
        }
    }
    printf("%d %d\n", minval, maxval);

    return 0;
}
