
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void readfromConsole(void)
{
	char input[1024];
    char* s;

   while (fgets(input, 1024, stdin) != NULL) 
   {
   
     /* Here we suppose the fgets() has reached a '\n' character... */
     for (char* s = input; (*s != '\n') && isspace(*s); s++)
        ; /* skipping blanks */
     if (*s == '\n')
        break; /* Blank line */
     else
        printf("the value of the input is %s\n", input); /* The input was not a blank line */
   }
	

}

int main()
{
	readfromConsole();
	return 0;
}
