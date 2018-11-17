#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main() {

	printf("Enter the string: ");
	char str[1024];
	gets(str);

	//Цикл в котором выводим строку в зеркальном отображении
	for (int i = strlen(str)-1; i >= 0; i--) {
		printf("%c", str[i]);
	}


	getchar();
	getchar();
}
