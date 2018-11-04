#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // strlen
#include <unistd.h>
#include <time.h>

char* ReadFile(char *filename)
{
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");

   if (handler)
   {
       // Seek the last byte of the file
       fseek(handler, 0, SEEK_END);
       // Offset from the first to the last byte, or in other words, filesize
       string_size = ftell(handler);
       // go back to the start of the file
       rewind(handler);

       // Allocate a string that can hold it all
       buffer = (char*) malloc(sizeof(char) * (string_size + 1) );

       // Read it all in one operation
       read_size = fread(buffer, sizeof(char), string_size, handler);

       // fread doesn't set it so put a \0 in the last position
       // and buffer is now officially a string
       buffer[string_size] = '\0';

       if (string_size != read_size)
       {
           // Something went wrong, throw away the memory and set
           // the buffer to NULL
           free(buffer);
           buffer = NULL;
       }

       // Always remember to close the file.
       fclose(handler);
    }

    return buffer;
}

double fileComprahance(char *file1, char *file2)
{
	double l1 = strlen(file1);
	double	equalSymb = 0;
	
	for(int i=0;i<l1-1;i++)
	{
		if(i == strlen(file2))
		{
			break;
		}
		
		if(file1[i] == file2[i])
		{
			equalSymb+=1;
		}
	}
	
	return (equalSymb/(l1-1)) * 100;
}

int main(int argn, char **args)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("inspection date: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	char *file1 = ReadFile(args[1]);
	char *file2 = ReadFile(args[2]);  	
	
	printf("Files: %s, %s\n",args[1],args[2]);
	
	if(strlen(file1)>strlen(file2))
	{
		printf("Percentage ratio: %lf\n", fileComprahance(file1, file2));		
	}
	else
	{
		printf("Percentage ratio: %lf\n", fileComprahance(file2, file1));
	}
    return 0;
}
