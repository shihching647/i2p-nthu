#include <stdio.h>

char text[10000005];

int main(void) {
//    freopen("12127_sampleIn.txt", "r", stdin);
    //1. getchar()
    char ch;
    while ((ch = getchar()) != EOF) //讀到EOF
        printf("%c", ch);
    
    //2. scanf()
//    char ch;
//    while (scanf("%c", &ch) != -1) { //沒讀到回傳-1
//        printf("%c", ch);
//    }
    
    //3.fgets()
//    while (fgets(text, 10000005, stdin) != NULL) { //沒讀到東西回傳NULL
//        printf("%s", text);
//    }
    /**
     不用在prinf("\n") 否則OJ會出現Presentation Error
     */
    return 0;
}
