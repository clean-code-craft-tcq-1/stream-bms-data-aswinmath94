
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void readfromConsole(void)
{
	char input[1024];

   while (1 == scanf("%[^\n]s", input)) {
        printf("the value of the input is %s\n", input); /* The input was not a blank line */
   }
	

}

int main()
{
	readfromConsole();
	return 0;
}
