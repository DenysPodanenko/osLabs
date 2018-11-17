#include <stdio.h>
#include <math.h>

int main(int argn, char **args)
{
	//open stream for write data
	FILE *f;
	f = fopen(args[1],"w");
	
	
	double start,end,h;
	//get variables values
	scanf("%lf%lf%lf",&start,&end,&h);
	
	//write answer od function into file
	for(double i = start;i<=end;i+=h)
	{
		double d = sin(i)+i-1;
		fprintf(f,"%lf: sin(x)+x-1 = %lf\n",i,d);
	} 
	fclose(f);
    	return 0;
}
