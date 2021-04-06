#include <stdio.h>
#include <string.h>

char a[100005];
char b[100005];

int is_equal(char* a, char* b, int length);

int main(void) {
    freopen("12133_sampleIn.txt", "r", stdin);
    scanf("%s%s", a, b);
    int result = 0;
    if (strlen(a) == strlen(b)) {
        result = is_equal(a, b, strlen(a));
    }
    if (result) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

// return 0代表不相同, 1代表相同
int is_equal(char* a, char* b, int length) {
    if (length == 1) {
        if (strncmp(a, b, 1) == 0) return 1;
        else return 0;
    }else if (strncmp(a, b, length) == 0) {
        return 1;
    } else if (length % 2 != 0) {
        return 0;
    } else {
        //(a1 == b1 && a2 == b2) || (a1 == b2 && a2 == b1)
        return (is_equal(a, b, length / 2) && is_equal(a + length / 2, b + length / 2, length / 2))
            || (is_equal(a, b + length / 2, length / 2) && is_equal(a + length / 2, b, length / 2)) ;
    }
}

