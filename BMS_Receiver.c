
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void readfromConsole(void)
{
	char input[1024];
	const char * InputArray[] = {
    "{'temperature':",
    "'soc':"
};

   while (scanf("%s\n", input) !=EOF) {
	    
        printf("the value of the input is %s\n", input); 
   }
	

}

int main()
{
	readfromConsole();
	return 0;
}
