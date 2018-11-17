#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // strlen
#include <unistd.h>

//function for reading text from file
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
	//text from file argumet 1
	char *string = ReadFile(args[1]);
	//word from argument 2
	char *word = args[2];   
	
	//convert to int position for insert 
	char *p;
	int position = strtol(args[3], &p, 10);
	
	//length of text
	size_t lstr = strlen(string);
	//length of word	
	size_t lword = strlen(word);
	//new array length text+word+1
	char* newString = (char*)malloc((lstr + lword + 1) * sizeof(char));
  	newString[lstr+lword] = '\0';

	//insert word in text
	int iterator=0;
	if(lstr<position)
	{
  		for(int i=0; i < lstr; i++) 
		{
    		newString[iterator] = string[i];
			iterator+=1;
  		}
	
		for(int i=0; i<lword; i++)
		{
			newString[iterator] = word[i];
			iterator+=1;
		}
	}
	else
	{
		for(int i=0; i<lstr;i++)
		{
			if(i == position)
			{
				for(int j=0; j<lword; j++)
				{
				newString[iterator] = word[j];
				iterator+=1;
				}
			}
			newString[iterator] = string[i];
			iterator+=1;
		}
	}
	
	//write new text in file argument 1	
	FILE *f;
	f = fopen(args[1], "w");
	fprintf(f,"%s",newString);	
	fclose(f);
    return 0;
}
