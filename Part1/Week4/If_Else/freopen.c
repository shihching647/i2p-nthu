#include <stdio.h>

int main(void) {
	char str[100];
	freopen("testcase.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%s", str);
	printf("輸出檔案\n%s\n", str);
	return 0;
}
