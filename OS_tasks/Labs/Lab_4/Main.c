#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main() {

	printf("Enter the string: ");
	char str[1024];
	gets(str);

	printf("What character to replace? ");
	char replace = getchar();
	//printf_s("%c", replace);

	printf("On which symbol to replace? "); 
	char prom = getchar();
	char which = getchar();
	//printf_s("%c", which);


	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == replace) {
			str[i] = which;
		}
	}

	printf("%s", str);


	getchar();
	getchar();
}
