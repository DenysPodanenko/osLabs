#include <stdio.h>
#include <math.h>

int main(int argn, char **args)
{
	FILE *f;
	f = fopen(args[1],"w");
	
	double start,end,h;
	scanf("%lf%lf%lf",&start,&end,&h);

	for(double i = start;i<=end;i+=h)
	{
		double d = sin(i)+i-1;
		fprintf(f,"%lf: sin(x)+x-1 = %lf\n",i,d);
	} 
	fclose(f);
    	return 0;
}
