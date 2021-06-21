
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	float min;
	float max;
}minMax_st;

// typedef struct
// {
	// Temperature;
	// SOC;
// }Typeofdata_st;
	
minMax_st minMax_data;
// Typeofdata_st TypeOfData;

void (*FindMinMaxofInput[])(float InputReading[],int numberOfReadings)={FindMinValue,FindMaxValue};

void readfromConsole(float Temperature[], float SOC[])
{
	char input[1024];
	int i,j,k=0;
	// static int paramindex=0;
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
		   if(paramindex % 2==0)
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

void FindMinMaxvalue(, )
{
	int loop_index=0;
	
	
}

void FindMinValue(float InputReading[], int numberOfReadings)
{

	int Loop_index=0;
	minMax_data.min=InputReading[0];
	for(Loop_index=1; Loop_index<numberOfReadings; Loop_index++)
	{
		if(minMax_data.min>InputReading[Loop_index])
			minMax_data.min=InputReading[Loop_index];
	}
}

void FindMaxValue(float InputReading[], int numberOfReadings)
{
	int Loop_index=0;
	minMax_data.max=InputReading[0];
	for(Loop_index=1; Loop_index<numberOfReadings; Loop_index++)
	{
		if(minMax_data.max<InputReading[Loop_index])
			minMax_data.max=InputReading[Loop_index];
	}
}

void MovingAvg(float arrayvalue[],int arraySize)
{
	int i=0;
	float avg=0;
	int j=0,k=0;
	float average[1024]={};

	for(i=0;i<arraySize;i++)
	{
		j++;
		if(j%5==0)
		{
			avg=arrayvalue[i]+arrayvalue[i-1]+arrayvalue[i-2]+arrayvalue[i-3]+arrayvalue[i-4];
			avg=(float)avg/5.00;
			j--;
			average[k]=avg;
			k++;
		}

		}

	}

int main()
{
	float Temperature[]={0};
	float SOC[]={0};
	int numberOfReadings=0;
	readfromConsole(Temperature,SOC );
	numberOfReadings= sizeof(Temperature) / sizeof(Temperature[0]);
	(*FindMinMaxofInput[0])(Temperature,numberOfReadings);
	(*FindMinMaxofInput[1])(Temperature,numberOfReadings);
	(*FindMinMaxofInput[0])(SOC,numberOfReadings);
	(*FindMinMaxofInput[1])(SOC,numberOfReadings);
    
    MovingAvg(Temperature,numberOfReadings);
	MovingAvg(SOC,numberOfReadings);
	return 0;
}
