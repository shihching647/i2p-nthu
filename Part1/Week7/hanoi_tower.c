#include <stdio.h>

int count;
void hanoi_tower(char start, char end, char buf, int n);

int main() {
    int n;
    printf("Number of disks: ");
    scanf("%d", &n);
    hanoi_tower('A', 'C', 'B', n);
    printf("Step count = %d\n", count);
}

void hanoi_tower(char start, char end, char buf, int n) {
    if (n <= 0) return;
    hanoi_tower(start, buf, end, n - 1); /* move the top n-1 disks from A to B */
    printf("Move %c -> %c\n", start, end);/* move the last disk from A to C */
    count++;
    hanoi_tower(buf, end, start, n - 1);/* move the top n-1 disks from B to C */
}

