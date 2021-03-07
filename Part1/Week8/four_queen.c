/**
 4個皇后的問題
 皇后可以走垂直水平
 也可以走斜對角
 如何在 4x4 的棋盤上擺放四個皇后
 使得她們互相不能一步吃掉對方
 */
#include <stdio.h>
#define N 4

int q[N]; //因為每個row只能有一個皇后, 所以可用一個一維陣列表示
/*
 ex:
 q[0] = 1 (0,1)
 q[1] = 0 (1,0)
 q[2] = 2 (2,2)
 q[3] = 3 (3,3)
 */

void show(void);
void place(int row);
int valid(int row, int col);
int count;

int main() {
    place(0);
    printf("count = %d\n", count);
    return 0;
}

void show() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (q[i] == j) printf("Q");
            else printf("-");
        }
        printf("\n");
    }
    printf("===========\n");
}

void place(int row) {
    if (row >= N) {
        count++;
        show();
        return;
    }
    for (int j = 0; j < N; j++) {
        if (valid(row, j)) {
            q[row] = j;
            place(row + 1);
        }
    }
}

int valid(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (q[i] == col) return 0;  //垂直線
        if (row - i == col - q[i] || row - i == q[i] - col) return 0; //對角線
    }
    return 1;
}
