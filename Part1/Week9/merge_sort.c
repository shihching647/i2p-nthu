/**
 Merge sort
 */

#include <stdio.h>
#define N 10000

int data[N];
int buffer[N];
void merge(int starta, int lena, int startb, int lenb);
void merge_sort(int l, int r);


int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", data + i);
    }
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

void merge_sort(int l, int r) {
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid - l + 1, mid + 1, r - mid);
    for (int i = 0; i < r - l + 1; i++) {
        data[l + i] = buffer[i];
    }
}

void merge(int starta, int lena, int startb, int lenb) {
    int i = 0, j = 0, k = 0; //index for a, b, buffer
    
    while (i < lena && j < lenb) {
        if (data[starta + i] < data[startb + j]) {
            buffer[k++] = data[starta + i++];
        } else {
            buffer[k++] = data[startb + j++];
        }
    }
    
    while (i < lena) {
        buffer[k++] = data[starta + i++];
    }
    
    while (j < lenb) {
        buffer[k++] = data[startb + j++];
    }
}
