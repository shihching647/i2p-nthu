/**
 列舉所有的二進位位元
 */

#include <stdio.h>

void show_bits(int n);
char bits[64];
int N;

int main(void) {
    printf("Please enter number of bits: ");
    scanf("%d", &N);
    bits[N] = '\0';
    show_bits(0);
    return 0;
}

void show_bits(int n) {
    if (n == N) {
        printf("%s\n", bits);
    } else {
        bits[n] = '0';
        show_bits(n + 1);
        bits[n] = '1';
        show_bits(n + 1);
    }
}
