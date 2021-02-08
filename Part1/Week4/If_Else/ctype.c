/*
 * 輸入一字串，然後1. 把空白字元拿掉 2. 把大寫換成小寫，小寫化成大寫 3. 數字了話，把原數字加2後輸出
 */

#include <stdio.h>
#include <ctype.h>

int main() {
	char c;
	int n;

	while ( (c = getchar()) != EOF ) {
		if (isspace(c)) continue;
		if (islower(c)) printf("%c\n", toupper(c));
		if (isupper(c)) printf("%c\n", tolower(c));
		if (isdigit(c)) {
			ungetc(c, stdin); //Unget character from stream
			scanf("%d", &n);
			printf("%d\n", n + 2);
		}
	}
	return 0;
}
