/**
 三座城堡問題
 在 3x3 的棋盤上擺三個城堡, 城堡走直線
 請找出彼此都不能一步吃掉對方的所有擺法
 (同一個row, 同一個col同時只能有一個城堡)
 */
#include <stdio.h>

int board[5][5];
void show(void);
void place(int row); //依照row擺
int valid(int row, int col);
int count;

int main(void) {
    place(1);
    printf("count =  %d\n", count);
    return 0;
}

void show() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (board[i][j]) printf("#");
            else printf("-");
        }
        printf("\n");
    }
    printf("============\n");
}

void place(int row) {
    //已擺3個
    if (row > 3) {
        show();
        count++;
        return;
    }
    for (int j = 1; j <= 3; j++) {
        if (valid(row, j)) {
            board[row][j] = 1; //放城堡
            place(row + 1);
            board[row][j] = 0;  //收回城堡
        }
    }
}

int valid(int row, int col) {
    for (int i = row; i >= 1; i--) {
        if (board[i][col])
            return 0;
    }
    return 1;
}
