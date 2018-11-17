#include <stdio.h>
//#include <iostream>
//#include <conio.h>

//Функция которая вычисляет максимальный элемент
void max(int mass[], int size) {
	int max = mass[0];
	for (int i = 1; i<size; i++)
		if (mass[i]>max) {
			max = mass[i];
		}

	printf("\nmax=%d", max);
}

//Функция которая вычисляет минимальный элемент
void min(int mass[], int size) {
	int min = mass[0];
	for (int i = 1; i<size; i++)
		if (mass[i]<min) {
			min = mass[i];
		}
	printf("\nmin=%d", min);
}

//Функция которая вычисляет среднее значение
void average(int mass[], int size) {
	int av;
	int sum = 0;
	for (int i = 0; i<size; i++)
	{
		sum += mass[i];
	}
	av = sum / size;
	printf("\naverage=%d", av);
}

int main() {
	int n = 8;
	int mass[n];
	
	//Заполняем массив
	for (int i = 0; i<n; i++)
	{
		printf("mass[%d] = ", i);
		scanf_s("%d", &mass[i]);
	}
	
	int size = sizeof(mass) / sizeof(int);

	

	max(mass,size);
	min(mass,size);
	average(mass, size);
	

	getchar();
}
