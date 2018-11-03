#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // strlen

int main(int argn, char **args)
{
	int c;
	FILE *file;
	file = fopen(args[1], "r");
		
	FILE *f;
	f = fopen(args[2],"w");
	if (file) 
	{
    		while ((c = getc(file)) != EOF)
        	{
			fprintf(f,"%d\n",c);
		}
    		fclose(file);
		fclose(f);
	}	
    	return 0;
}
