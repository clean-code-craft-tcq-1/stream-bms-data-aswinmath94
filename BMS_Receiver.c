
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void readfromConsole(void)
{
	char input[1024];
	float Temperature[30]={};
	float SOC[30]={};
	int i,j=0;
	int paramindex=0;
	const char * InputArray[] = {
    "{'temperature':",
    "'soc':" };

   while (scanf("%s\n", input) !=EOF) 
   {
	   if ( (input== InputArray[0])|| (input== InputArray[1]))
	   {
		   printf("the value of the character is %s\n", input);
	    continue;
	   }
	   else
	   {
		   
			   i = strlen(input);
               InputArray[i] = '\n';
               InputArray[i + 1] = '\0';
		   if(paramindex%1!=0)
		   {
			   Temperature[j]= atof(InputArray);
			   printf("the value of the temp is %s\n", input);
			   paramindex++;
		   }
		   else 
		   {
			   SOC[j]=atof(InputArray);
			   printf("the value of the SOC is %s\n", input);
			   paramindex=0;
		   }
		   j++;
	   }
          
   }
	

}

int main()
{
	readfromConsole();
	return 0;
}
