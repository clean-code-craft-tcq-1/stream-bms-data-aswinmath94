

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "BMS_Receiver.h"

int lengthOfInputData=0;
minMax_st minMax_data;
float Temperature[MAX_SIZE_TO_READ]={};
float SOC[MAX_SIZE_TO_READ]={};

ResultType (*FindMinMaxofInput[])(float InputReading[])={FindMinValue,FindMaxValue};



ResultType FindMinandMaxValue(float InputReading[], UserRequestOperation UserRequestOperator)
{
	ResultType UserRequestSuccess= Failure;
	UserRequestSuccess=(*FindMinMaxofInput[UserRequestOperator])(InputReading);
	return UserRequestSuccess;
}
	

ResultType readfromConsole(float Temperature[], float SOC[])
{
	char InputData[1024];
	ResultType ReadConsoleSuccess= Failure;
   while (scanf("%s\n", InputData) !=EOF) 
   {
	  ReadConsoleSuccess= ProcessReadData(InputData, Temperature, SOC);
   }
   return ReadConsoleSuccess;
}

ResultType ProcessReadData(char *InputData, float Temperature[], float SOC[])
{
	int ResultComparetemp,ResultCompareSOC=0;
	ResultType ProcessedDataSuccess= Failure;
	const char * InputArray_Dontprocess[] = {
											"{'temperature':",
											"'soc':" };
	   ResultComparetemp=strcmp(InputData, InputArray_Dontprocess[0]); 
	   ResultCompareSOC= strcmp(InputData, InputArray_Dontprocess[1]);
	   if(( ResultComparetemp ==0) || (ResultCompareSOC ==0))
	   {

		  ProcessedDataSuccess=Success;
  	   }
	   else
	   {
		 ProcessedDataSuccess=  ExtractBatteryData_FromInput(InputData, Temperature, SOC);
	   }
	   return ProcessedDataSuccess;
}  

ResultType ExtractBatteryData_FromInput(char *InputData, float Temperature[], float SOC[])
{
	ResultType BatteryDataReady= Failure;
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
	   (void)FindMovingAverage(Temperature, Temperature_index);
	   BatteryDataReady=Success;
    }
    else 
    {
	   SOC[SOC_index]=strtod(InputData,NULL);
	   printf("the value of the SOC is %0.6f\n", SOC[SOC_index]);
	   SOC_index++;
	   lengthOfInputData++;
	   (void)FindMovingAverage(SOC,SOC_index);
	   BatteryDataReady=Success;
    }
    paramindex++;


    return BatteryDataReady;
		   
}


ResultType FindMinValue(float InputReading[])
{

	ResultType FoundMinValue= Failure;
	int Loop_index=0;
	minMax_data.min=InputReading[0];
	for(Loop_index=1; Loop_index< lengthOfInputData; Loop_index++)
	{
		if(minMax_data.min>InputReading[Loop_index])
			minMax_data.min=InputReading[Loop_index];
		FoundMinValue=Success;
	}
	printf("the value of the min is %f\n", minMax_data.min);
	return FoundMinValue;
}

ResultType FindMaxValue(float InputReading[])
{
	ResultType FoundMaxValue= Failure;
	int Loop_index=0;
	minMax_data.max=InputReading[0];
	for(Loop_index=1; Loop_index<lengthOfInputData; Loop_index++)
	{
		if(minMax_data.max<InputReading[Loop_index])
			minMax_data.max=InputReading[Loop_index];
		FoundMaxValue=Success;
	}
	printf("the value of the max is %f\n", minMax_data.max);
	return FoundMaxValue;
}

ResultType FindMovingAverage(float arrayvalue[], int lengthofData)
{
	int Loop_counter=0;
	ResultType FoundMovingAverage= Failure;
	float avg=0;
	int Modvalue=0,Array_index=0;
	float average[1024]={};


    for(Loop_counter=0; (lengthofData>=5)&&(Loop_counter<lengthofData);Loop_counter++)
	 {
		Modvalue++;
		if(Modvalue%5==0)
		{
			avg=arrayvalue[Loop_counter]+arrayvalue[Loop_counter-1]+arrayvalue[Loop_counter-2]+arrayvalue[Loop_counter-3]+arrayvalue[Loop_counter-4];
			avg=(float)avg/5.00;
		    Modvalue--;
		    average[Array_index]=avg;
			Array_index++;
		    FoundMovingAverage=Success;
			
		}

	 }
	  for (int m=0;(lengthofData>=5)&& m<lengthofData; m++)
	  {
		  printf("the value of the average is %f\n", average[m]);
	  }
	return FoundMovingAverage;
}
