/**
 假設今天給你一個班所有同學（10位學生 0 ~ 99)的成績，找出
 1.全班最高分的分數
 2.有多少人及格
 3.全班平均
 4標準差
 5.成績用樹狀圖表示
 */

#include <stdio.h>
#include <math.h>
#define NUMBER_OF_STUDENT 10

int score[NUMBER_OF_STUDENT];
void read_score(void);
int highest(void);
int pass(int);
double average(void);
long double standard_deviation(double);
void graph(void);

int main() {
    double ave;
    read_score();
    printf("The highest score: %d\n", highest());
    printf("The number of pass: %d\n", pass(60));
    ave = average();
    printf("The average: %lf\n", ave);
    printf("The standard deviation: %Lf\n", standard_deviation(ave));
    graph();
}

void read_score() {
    freopen("scores.txt", "r", stdin);
    for (int i = 0; i < NUMBER_OF_STUDENT; i++) {
        scanf("%d", score + i);
    }
}

int highest() {
    int highest = score[0];
    for (int i = 1; i < NUMBER_OF_STUDENT; i++) {
        if (score[i] > highest)
            highest = score[i];
    }
    return highest;
}

int pass(int value) {
    int count = 0;
    for (int i = 0; i < NUMBER_OF_STUDENT; i++) {
        if (score[i] >= value)
            count++;
    }
    return count;
}

double average() {
    double sum = 0;
    for (int i = 0; i < NUMBER_OF_STUDENT; i++) {
        sum += score[i];
    }
    return sum / NUMBER_OF_STUDENT;
}

long double standard_deviation(double ave) {
    long double sd = 0;
    for (int i = 0; i < NUMBER_OF_STUDENT; i++) {
        sd += pow(score[i] - ave, 2);
    }
    sd /= NUMBER_OF_STUDENT;
    return sqrt(sd);
}

void graph() {
    printf("\n-------distribution------\n");
    int tree[101] = {0};
    for (int i = 0; i < NUMBER_OF_STUDENT; i++) {
        tree[score[i]]++;
    }
    for (int i = 1; i < 101; i++) {
        printf("%d: ", i);
        for (int j = 0; j < tree[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}
