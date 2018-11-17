#include <stdio.h>
#include <math.h>

double function(double x)
{
	return 1/(1-cos(x));
}

void main() {
	
	float a, b, n;

	printf("Input a = ");
	scanf("%f",&a);

	printf("Input b = ");
	scanf("%f", &b);

	printf("Input n = ");
	scanf("%f", &n);

	printf("%f", a);

	

	for (float i = a; i <= b; i += n) {
		printf( "\nF(x) = %f ", function(i) );

	}


	getchar();
	getchar();
}
