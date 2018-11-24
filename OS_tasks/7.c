#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // strlen
#include <unistd.h>
#include <ctype.h>

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
	char *string = ReadFile(args[1]);
    
	char *encryptString = string;
	char *p;
	int h = strtol(args[2], &p, 10);
	for(int i=0;i<strlen(string);i++)
	{
		int bigNum = 0;
		int numChar = encryptString[i];
		if(numChar>64 && numChar<91)
		{
			bigNum = 1;
			numChar = tolower(numChar);
		}
		//printf("big num - %d",bigNum);
		if(numChar<97 || numChar>122)
		{
			continue;
		}		
		
		if(numChar+h>122)
		{
			int k = numChar + h - 122;
			numChar=k+97;
		}
		else
		{
			numChar+=h;			
		}
		
		char ch = numChar;
		if(bigNum == 1)
		{
			ch = toupper(ch);
		}
		//printf("%d\n",h);
		encryptString[i] = ch;
	}	
	

	printf("%s",encryptString);
    	return 0;
}
