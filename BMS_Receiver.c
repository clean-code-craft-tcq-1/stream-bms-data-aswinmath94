
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void readfromConsole(void)
{
	char input[1024];
    char* s;

   while (1 == scanf("%[^\n]%*c", input)) {
        printf("the value of the input is %s\n", input); /* The input was not a blank line */
   }
	

}

int main()
{
	readfromConsole();
	return 0;
}
