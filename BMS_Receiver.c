
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct
{
	float min;
	float max;
}minMax;
float Temperature[1024]={};
float SOC[1024]={};

minMax minMax1;

void readfromConsole(void)
{
	char input[1024];
	
	int i,j,k=0;
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
			   j++;
		   }
		   else 
		   {
			   SOC[k]=atof(input);
			   printf("the value of the SOC is %f\n", SOC[k]);
			   k++;
		   }
		   paramindex++;
		   
		   
	   }
          
   }
	

}


void findMinMax(float arrayvalue[])
{

	int i=0;
	minMax1.min=minMax1.max=arrayvalue[0];
	for(i=1; i<10; i++)
	{
		if(minMax1.min>arrayvalue[i])
			minMax1.min=arrayvalue[i];
		if(minMax1.max<arrayvalue[i])
			minMax1.max=arrayvalue[i];
	}
}

void MovingAvg(float arrayvalue[],int arraySize)
{
	int i=0;
	float avg=0;
	int j=0,k=0;
	float Average[30]={};

	for(i=0;i<arraySize;i++)
	{
		j++;
		if(j%5==0)
		{
			avg=arrayvalue[i]+arrayvalue[i-1]+arrayvalue[i-2]+arrayvalue[i-3]+arrayvalue[i-4];
			avg=(float)avg/5.00;
			j--;
			Average[k]=avg;
			k++;
		}

	}

}


int main()
{
	readfromConsole();
	// findMinMax(Temperature);
	// findMinMax(SOC);
	// MovingAvg(Temperature,30);
	return 0;
}
