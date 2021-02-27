#include <stdio.h>
#define MAP_SIZE 12
#define CAR_SIZE 3
//#define ONLINE_JUDGE

int map[MAP_SIZE][MAP_SIZE];
void map_reset(void);

void map_show(void);

int blocks[MAP_SIZE][MAP_SIZE];
void blocks_read(void);
void blocks_put_on_map(void);

int jewels[MAP_SIZE][MAP_SIZE];
void jewels_read(void);
void jewels_put_on_map(void);

int car[CAR_SIZE][CAR_SIZE] = {{'O', 'O', '@'}, {'O', 'O', 'O'}, {'O', 'O', '@'}};
int car_row = 3, car_col = 4; //初始位置
int speed = 1;
int car_direction; //0:右, 1:下, 2:左, 3:上
int car_earnings;
void car_rotate90(void);
void car_put_on_map(void);
void car_move(void);
void upgrade(void);

int main(void)
{
    int ch;

    blocks_read();

    jewels_read();

    printf("Read actions!\n");
#ifndef ONLINE_JUDGE
    freopen("actions.txt", "r", stdin);
#endif

    while ((ch=getchar()) != EOF) {
        if (ch == '\n') continue; //避免讀到'\n'多印一次map
        if (ch=='R') {
            car_rotate90();
        }

        if (ch=='F') {
            car_move();
        }

        map_reset();

        blocks_put_on_map();

        jewels_put_on_map();

        car_put_on_map();

#ifndef ONLINE_JUDGE
        map_show();
#endif
    }


    printf("Earnings: %d\n", car_earnings);

    printf("Position: row=%d, col=%d\n", car_row, car_col);

    char dirs[] = "RDLU";

    printf("Direction: %c\n", dirs[car_direction]);


    return 0;
}

/*
 從檔案或stdin讀取blocks座標位置，記錄在blocks二維陣列裡
 */
void blocks_read(void)
{
    int n, i;
    int row, col;
    printf("Read blocks!\n");
#ifndef ONLINE_JUDGE
    freopen("blocks.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d%d", &row, &col);
        blocks[row][col] = 1;
    }
}

/*
 從檔案或stdin讀取jewels座標位置，記錄在jewels二維陣列裡
 */
void jewels_read(void)
{
    int n, i;
    int row, col;
    printf("Read jewels!\n");
#ifndef ONLINE_JUDGE
    freopen("jewels.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d%d", &row, &col);
        jewels[row][col]++;
    }
}

/*
 把blocks座標位置顯示在map上
 */
void blocks_put_on_map(void)
{
    int i, j;

    for (i=0; i<MAP_SIZE; i++) {

        for (j=0; j<MAP_SIZE; j++) {

            if (blocks[i][j])

                map[i][j] = '#';
        }
    }
}

/*
 把jewels座標位置顯示在map上
 */
void jewels_put_on_map()
{
    int i, j;

    for (i=0; i<MAP_SIZE; i++) {

        for (j=0; j<MAP_SIZE; j++) {

            if (jewels[i][j] == 1)
                map[i][j] = '$';
            else if (jewels[i][j] > 1)
                map[i][j] = 'S';
        }
    }
}

/*
 重新建立新的顯示map
 */
void map_reset(void)
{
    int i, j;

    for (i=0; i<MAP_SIZE; i++) {

        for (j=0; j<MAP_SIZE; j++) {

            map[i][j] = '.';
        }
    }
    for (i=0; i<MAP_SIZE; i++) {

        map[i][0] = 'H';

        map[i][MAP_SIZE-1] = 'H';
    }
    for (j=0; j<MAP_SIZE; j++) {

        map[0][j] = 'H';

        map[MAP_SIZE-1][j] = 'H';
    }
}

/*
 將結果顯示在console上
 */
void map_show(void)
{
    int i, j;

    for (i=0; i<MAP_SIZE; i++) {

        for (j=0; j<MAP_SIZE; j++) {

            printf("%c", map[i][j]);

        }
        printf("\n");
    }

}

/*
 把car座標位置顯示在map上
 */
void car_put_on_map(void)
{
    int i, j;
    for (i=0; i<CAR_SIZE; i++) {

        for (j=0; j<CAR_SIZE; j++) {

            map[i+car_row][j+car_col] = car[i][j];
        }
    }
}

/*
 車子向右旋轉90度
 car_direction -> 0:右, 1:下, 2:左, 3:上
 OO@
 OOO
 OO@
 */
void car_rotate90(void)
{
    car_direction = (car_direction + 1) % 4;
    
    int temp;
    if (car_direction % 2) {
        temp = car[0][2];
        car[0][2] = car[2][0];
        car[2][0] = temp;
    } else {
        temp = car[0][0];
        car[0][0] = car[2][2];
        car[2][2] = temp;
    }
}


int is_legal_move(int row, int col) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (blocks[row + i][col + j] || map[row + i][col + j] == 'H' )
                return 0;
        }
    }
    return 1;
}

void reset_jewels(int row, int col) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jewels[row + i][col + j] < 0) {
                jewels[row + i][col + j] *= -1; //把寶物的值改回正的
            }
        }
    }
}

void pick_jewels(int row, int col) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jewels[row + i][col + j] > 0) {
                jewels[row + i][col + j]--;
                jewels[row + i][col + j] *= -1; //超過一個寶物時, 改成負值
                car_earnings++;
            }
        }
    }
}

void upgrade() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(car[i][j] == '@') car[i][j] = 'X';
            if(car[i][j] == 'O') car[i][j] = '*';
        }
    }
    speed = 2;
}

/*
 車子前進
 */
void car_move(void)
{
    int car_row_try = car_row;
    int car_col_try = car_col;
    // 分別對上 0:右, 1:下, 2:左, 3:上, 取代if else 的寫法
    int row_dict[] = {0, 1, 0, -1};
    int col_dict[] = {1, 0, -1, 0};
    int row_delta = row_dict[car_direction] * speed;
    int col_delta = col_dict[car_direction] * speed;
    car_row_try = car_row_try + row_delta;
    car_col_try = car_col_try + col_delta;
    if (is_legal_move(car_row_try, car_col_try)) {
        car_row = car_row_try;
        car_col = car_col_try;
        //當車子撿寶物上時, 把有超過一個寶物的位置的值改成負值, 當車子離開寶物時,再reset_jewels(把負值改成正值)
        reset_jewels(car_row - row_delta, car_col - col_delta);
        pick_jewels(car_row, car_col);
        //upgrade
        if (car_earnings >= 1 && speed == 1) {
            car_earnings -= 1;
            upgrade();
        }
    }
}


