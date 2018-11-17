#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // strlen
#include <unistd.h>

//function for read all text from file
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

int main(int argn, char **args)
{
	//text from file argument 1
	char *string = ReadFile(args[1]);
    	
	//encrypt text
	char *encryptString = string;
	
	//convert int from second argument 2, key
	char *p;
	int h = strtol(args[2], &p, 10);
		
	//encrypting text
	for(int i=0;i<strlen(string);i++)
	{
		int numChar = encryptString[i];
		
		if(numChar<97 || numChar>122)
		{
			continue;
		}		
		
		if(numChar+h>122)
		{
			while(1)
			{
				if(numChar+h>122)
				{
					numChar-=122;
				}
				else
				{
					break;
				}
			}
			numChar+=h;
		}
		else
		{
			numChar+=h;			
		}
		
		char ch = numChar;
		//printf("%d\n",h);
		encryptString[i] = ch;
	}	
	
	//print text on console
	printf("%s",encryptString);
    	return 0;
}
