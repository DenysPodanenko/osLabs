#include <stdio.h>
#include <math.h>

//Функция которая возвращает значение заданной функции
double function(double x)
{
	return 1/(1-cos(x));
}

void main() {
	
	float a, b, n;

	//Вводим границу a
	printf("Input a = ");
	scanf("%f",&a);
	
	//Вводим границу b
	printf("Input b = ");
	scanf("%f", &b);
	
	//Вводим шаг n
	printf("Input n = ");
	scanf("%f", &n);

	printf("%f", a);

	
	//Вычисляем функцию с заданными параметрами
	for (float i = a; i <= b; i += n) {
		printf( "\nF(x) = %f ", function(i) );

	}


	getchar();
	getchar();
}
