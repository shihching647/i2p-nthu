#include <stdio.h>

int main() {
    char command[100000];
    int n, countL = 0, countR = 0;
    scanf("%d", &n);
    scanf("%s", command);
    for (int i = 0; i < n; i++) {
        if (command[i] == 'R') countR++;
        else countL++;
    }
    printf("%d\n", countL + countR + 1);
}
