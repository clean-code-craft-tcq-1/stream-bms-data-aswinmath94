#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "BMS_Receiver.h"

int lengthOfInputData=0;
minMax_st minMax_data;
float Temperature[MAX_SIZE_TO_READ]={};
float SOC[MAX_SIZE_TO_READ]={};

ResultType (*FindMinMaxofInput[])(float InputReading[])={FindMinValue,FindMaxValue};
const char *BatteryMessage[] =
{
    "Temperature",
    "State Of Charge"
};

/**
 ***************************************************************************************************
 * Function Name: FindMinandMaxValue
 * 
 * Function Description: Finds the Minimum or maximum value of the input array passed in the argument depending on the value of UserRequestOperator.
 *
 * \param  float InputReading[] :- array to find the Min or Max.
 *         UserRequestOperation UserRequestOperator:- UserRequestOperator= ToFindMinValue finds the minimum value , UserRequestOperator= ToFindMaxValue finds the maximum value.
 *   
 *         
 * \return  ResultType (user defined enum)
 * \retval  Success or failure indicating execution status of Requested operation.
 ***************************************************************************************************
 */
ResultType FindMinandMaxValue(float InputReading[], UserRequestOperation UserRequestOperator)
{
	ResultType UserRequestSuccess= Failure;
	UserRequestSuccess=(*FindMinMaxofInput[UserRequestOperator])(InputReading);
	
	return UserRequestSuccess;
}
	
/**
 ***************************************************************************************************
 * Function Name: readfromConsole
 * 
 * Function Description: Finds the Minimum or maximum value of the input array passed in the argument depending on the value of UserRequestOperator.
 *
 * \param  float Temperature[] :- array to fill the read 1st data from stdin(console)
 *         float SOC[] :- array to fill the read 2nd data from stdin(console)
 *   
 *         
 * \return  ResultType (user defined enum)
 * \retval  Success or failure indicating execution status of Data reading process.
 ***************************************************************************************************
 */
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
/**
 ***************************************************************************************************
 * Function Name: ProcessReadData
 * 
 * Function Description: Process the read data to segragate useful value for Receiver process.
 *
 * \param  char *InputData :-  to read string continuously
 *         float Temperature[]:- array to fill the read 1st data from stdin(console)
 *         float SOC[] :- array to fill the read 2nd data from stdin(console)
 *   
 *         
 * \return  ResultType (user defined enum)
 * \retval  Success or failure indicating execution status of Data reading process.
 ***************************************************************************************************
 */
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
/**
 ***************************************************************************************************
 * Function Name: ExtractBatteryData_FromInput
 * 
 * Function Description: Extract the float value after segragating string data
 *
 * \param  char *InputData :-  to read string continuously
 *         float Temperature[]:- array to fill the read 1st data from stdin(console)
 *         float SOC[] :- array to fill the read 2nd data from stdin(console)
 *   
 *         
 * \return  ResultType (user defined enum)
 * \retval  Success or failure indicating execution status of Useful data extraction
 ***************************************************************************************************
 */
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
	   Temperature_index++;
	   BatteryDataReady=Success;
    }
    else 
    {
	   SOC[SOC_index]=strtod(InputData,NULL);
	   SOC_index++;
	   lengthOfInputData++;
	   BatteryDataReady=Success;
    }
    paramindex++;


    return BatteryDataReady;
		   
}

/**
 ***************************************************************************************************
 * Function Name: FindMinValue
 * 
 * Function Description: Extract the float value after segragating string data
 *
 * \param  float InputReading[]:- Array on which minimum value have to be calcutated upon
 *         
 *   
 *         
 * \return  ResultType (user defined enum)
 * \retval  Success or failure indicating execution status of Finding of minimum value.
 ***************************************************************************************************
 */
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
	return FoundMinValue;
}
/**
 ***************************************************************************************************
 * Function Name: FindMaxValue
 * 
 * Function Description: Extract the float value after segragating string data
 *
 * \param  float InputReading[]:- Array on which Maximum value have to be calcutated upon
 *         
 *   
 *         
 * \return  ResultType (user defined enum)
 * \retval  Success or failure indicating execution status of Finding of Maximum value.
 ***************************************************************************************************
 */
ResultType FindMaxValue(float InputReading[] )
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
	return FoundMaxValue;
}
/**
 ***************************************************************************************************
 * Function Name: FindMovingAverage
 * 
 * Function Description: Extract the float value after segragating string data
 *
 * \param  float InputArray[] :-  Dataarray on which moving average needs to be found
 *         int lengthofData:- Length of data on which moving average needs to be found.
 *         float OutputAveragearray[]:-  Output parameter : Averaged data is output
 *         
 * \return  ResultType (user defined enum)
 * \retval  Success or failure indicating execution status of Finding moving average of input array value.
 ***************************************************************************************************
 */
ResultType FindMovingAverage(float InputArray[], int lengthofData, float OutputAveragearray[])
{
    int Loop_counter=0;
	ResultType FoundMovingAverage= Failure;
	float avg=0;
    int Modvalue=0;
    int Array_index=0;

    for(Loop_counter=0; Loop_counter<lengthofData;Loop_counter++)
	 {
		Modvalue++;
		if(Modvalue%5==0)
		{
			avg=InputArray[Loop_counter]+InputArray[Loop_counter-1]+InputArray[Loop_counter-2]+InputArray[Loop_counter-3]+InputArray[Loop_counter-4];
			avg=(float)avg/5.00;
		    Modvalue--;
		    OutputAveragearray[Array_index]=avg;
			Array_index++;
		    FoundMovingAverage=Success;
			
		}

	 }

	return FoundMovingAverage;
}
/**
 ***************************************************************************************************
 * Function Name: PrintToConsole
 * 
 * Function Description: Function prints the data of minimum, maximum,moving average of 5
 *
 * \param  float PrintData[] :-  Array value needed to print
 *         PrintingData DataToPrint:- Collection of data provided as input to be output on the console.
 *                  
 * \return  ResultType (user defined enum)
 * \retval  Success or failure indicating execution status of Printing to console.
 ***************************************************************************************************
 */
ResultType PrintToConsole( float PrintData[],PrintingData DataToPrint)
{
	 ResultType PrintedToConsole= Failure;
	 printf( " The Maximum value of the %s data received is %f \n", BatteryMessage[DataToPrint.IndexOfBatteryMessage],minMax_data.max );
	 printf( " The Minimum value of the %s data received is %f \n", BatteryMessage[DataToPrint.IndexOfBatteryMessage],minMax_data.min );
	
	 for(int Loopcount=0; Loopcount< DataToPrint.LengthOfAvgArray;Loopcount++)
	 {
        printf("The value of the average of %s is %f\n", BatteryMessage[DataToPrint.IndexOfBatteryMessage],PrintData[Loopcount]);
	 }
	 PrintedToConsole=Success;
	 return PrintedToConsole;
	 
}