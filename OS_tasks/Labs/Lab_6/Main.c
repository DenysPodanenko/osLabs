#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <fstream>
//#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)



void main() {

	FILE *file;
	FILE *file2;
	char arr[2048];

	//Открываем поток на считывание файла
	file = fopen("fscanf.txt", "r");
	
	//Открываем поток на запись файла
	file2 = fopen("out.txt", "w");
	int i = 0;
	//Считываем пока не конец фала
	while ((arr[i] = fgetc(file)) != EOF) {
		if (arr[i] == '\n') {
			arr[i] = '\0';
			printf("%s\n", arr);
			//Если код символа находится в заданом промежутке, тогда пропускаем его
			if (arr[i] >= 100 && arr[i] <= 110)
				continue;
			putc(arr[i], file2);
			i = 0;
		}
		//Если нет - сохраняем в массив
		else {
			if (arr[i] >= 100 && arr[i] <= 110)
				continue;
			putc(arr[i], file2);
			i++;
		}	
	}
	arr[i] = '\0';
	printf("%s\n", arr);

	char prom;
	//Записываем массив в новый файл
	while (!feof(file)) {
		prom = fgetc(file);
		putc(prom, file2);
	}


	getchar();
	getchar();
}
