#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // strlen

int main(int argn, char **args)
{
	int c;
	//open stream for reading
	FILE *file;
	file = fopen(args[1], "r");
		
	//open stream for writing
	FILE *f;
	f = fopen(args[2],"w");
	if (file) 
	{
		//write numeric format into new file
    		while ((c = getc(file)) != EOF)
        	{
			fprintf(f,"%d\n",c);
		}
    		fclose(file);
		fclose(f);
	}	
    	return 0;
}
