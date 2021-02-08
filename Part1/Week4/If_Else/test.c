#include<stdio.h>

int main(void)
{
    char c;
    
    while ( (c = getchar() ) != EOF )
    {
		if (c == '\n') continue;
        printf("c = ");
        putchar(c);
        printf("\n");
    }
    return 0;
}
