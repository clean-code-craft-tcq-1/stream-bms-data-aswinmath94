
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
	int paramindex,Result,Result1=0;
	const char * InputArray[] = {
    "{'temperature':",
    "'soc':" };

   while (scanf("%s\n", input) !=EOF) 
   {
	   Result=strcmp(input, InputArray[0]); 
	   Result1=strcmp(input, InputArray[1]);
	   if(( Result ==0) || (Result1 ==0))
	   {
		   printf("the value of the character is %s\n", input);
	    
	   }
	   else
	   {
		   
			   i = strlen(input);
               input[i-1] = '\0';
               // input[i + 1] = '\0';
		   if(paramindex%2==0)
		   {
			   Temperature[j]= atof(input);
			   printf("the value of the temp is %f\n", Temperature[j]);
			   paramindex++;
		   }
		   else 
		   {
			   SOC[j]=atof(input);
			   printf("the value of the SOC is %f\n", SOC[j]);
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
