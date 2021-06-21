

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "BMS_Receiver.h"

typedef struct
{
	float min;
	float max;
}minMax_st;


minMax_st minMax_data;


void (*FindMinMaxofInput[])(float InputReading[],int numberOfReadings)={FindMinValue,FindMaxValue};

void readfromConsole(float Temperature[], float SOC[])
{
	char InputData[1024];
	
   while (scanf("%s\n", InputData) !=EOF) 
   {
	   ProcessReadData(InputData, Temperature, SOC);
   }
}

void ProcessReadData(char InputData[], float Temperature[], float SOC[])
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
		   ExtractBatteryData_FromInput(InputData, Temperature, SOC);
	   }
}  

void ExtractBatteryData_FromInput(char InputData[], float Temperature[], float SOC[])
{
	int InputStringlen=0;
	int Temperature_index=0;
	int SOC_index=0;
	int paramindex=0;
	
		   InputStringlen = strlen(InputData);
		   InputData[InputStringlen-1] = '\0';
		   if(paramindex % 2==0)
		   {
			   Temperature[Temperature_index]= atof(InputData);
			   printf("the value of the temp is %f\n", Temperature[Temperature_index]);
			   Temperature_index++;
		   }
		   else 
		   {
			   SOC[SOC_index]=atof(InputData);
			   printf("the value of the SOC is %f\n", SOC[SOC_index]);
			   SOC_index++;
		   }
		   paramindex++;

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
	float Temperature[]={};
	float SOC[]={};
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
