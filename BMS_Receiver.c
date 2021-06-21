

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "BMS_Receiver.h"

int lengthOfInputData=0;
minMax_st minMax_data;


void (*FindMinMaxofInput[])(float *InputReading)={FindMinValue,FindMaxValue};

void readfromConsole(float *Temperature, float *SOC)
{
	char InputData[1024];
	
   while (scanf("%s\n", InputData) !=EOF) 
   {
	   ProcessReadData(&InputData, &Temperature, &SOC);
   }
}

void ProcessReadData(char *InputData, float *Temperature, float *SOC)
{
	int ResultComparetemp,ResultCompareSOC=0;
	const char * InputArray_Dontprocess[] = {
											"{'temperature':",
											"'soc':" };
	   ResultComparetemp=strcmp(InputData, InputArray_Dontprocess[0]); 
	   ResultCompareSOC= strcmp(InputData, InputArray_Dontprocess[1]);
	   if(( ResultComparetemp ==0) || (ResultCompareSOC ==0))
	   {
		  //do nothing
  	   }
	   else
	   {
		   ExtractBatteryData_FromInput(&InputData, &Temperature, &SOC);
	   }
}  

void ExtractBatteryData_FromInput(char *InputData, float *Temperature, float *SOC)
{
	int InputStringlen=0;
	static int Temperature_index=0;
	static int SOC_index=0;
	static int paramindex=0;
	
		   InputStringlen = strlen(InputData);
		   InputData[InputStringlen-1] = '\0';
		   if(paramindex % 2==0)
		   {
			   Temperature[Temperature_index]= strtod(InputData,NULL);
			   printf("the value of the temp is %0.6f\n", Temperature[Temperature_index]);
			   Temperature_index++;
		   }
		   else 
		   {
			   SOC[SOC_index]=strtod(InputData,NULL);
			   printf("the value of the SOC is %0.6f\n", SOC[SOC_index]);
			   SOC_index++;
			   lengthOfInputData++;
		   }
		   paramindex++;
		   
}


void FindMinValue(float *InputReading)
{

	int Loop_index=0;
	minMax_data.min=InputReading[0];
	for(Loop_index=1; Loop_index< lengthOfInputData; Loop_index++)
	{
		if(minMax_data.min>InputReading[Loop_index])
			minMax_data.min=InputReading[Loop_index];
	}
	printf("the value of the min is %f\n", minMax_data.min);
}

void FindMaxValue(float *InputReading)
{
	int Loop_index=0;
	minMax_data.max=InputReading[0];
	for(Loop_index=1; Loop_index<lengthOfInputData; Loop_index++)
	{
		if(minMax_data.max<InputReading[Loop_index])
			minMax_data.max=InputReading[Loop_index];
	}
	printf("the value of the max is %f\n", minMax_data.max);
}

void MovingAvg(float *arrayvalue)
{
	int Loop_counter=0;
	float avg=0;
	int Modvalue=0,Array_index=0;
	float average[1024]={};

	for(Loop_counter=0;Loop_counter<lengthOfInputData;Loop_counter++)
	{
		Modvalue++;
		if(Modvalue%5==0)
		{
			avg=arrayvalue[Loop_counter]+arrayvalue[Loop_counter-1]+arrayvalue[Loop_counter-2]+arrayvalue[Loop_counter-3]+arrayvalue[Loop_counter-4];
			avg=(float)avg/5.00;
			Modvalue--;
			average[Array_index]=avg;
			Array_index++;
			
		}

	}
	for (int m=0; m<lengthOfInputData; m++)
	{
		printf("the value of the average is %f\n", average[m]);
	}
}

int main()
{
	float Temperature[]={};
	float SOC[]={};
	int numberOfReadings=0;
	readfromConsole(&Temperature,&SOC );
	for (int i=0;i< lengthOfInputData;i++)
	{
	   printf("the value of the temp in main is %0.6f\n", Temperature[i]);
	   printf("the value of the SOC in main is %f\n", SOC[i]);
	}
	
	
	(*FindMinMaxofInput[0])(&Temperature);
	(*FindMinMaxofInput[1])(&Temperature);
	(*FindMinMaxofInput[0])(&SOC);
	(*FindMinMaxofInput[1])(&SOC);
    
    MovingAvg(&Temperature);
	MovingAvg(&SOC);
	return 0;
}
