#include <stdio.h>


typedef struct
{
	float min;
	float max;
}minMax_st;

typedef enum
{
	Failure,
	Success
}ResultType;

typedef enum
{
	ToFindMinValue,
	ToFindMaxValue
}UserRequestOperation;

#define MAX_SIZE_TO_READ 400

extern float Temperature[MAX_SIZE_TO_READ];
extern float SOC[MAX_SIZE_TO_READ];
extern minMax_st minMax_data;
extern int lengthOfInputData;
ResultType FindMaxValue(float InputReading[]);
ResultType FindMinValue(float InputReading[]);
ResultType ExtractBatteryData_FromInput(char *InputData, float Temperature[], float SOC[]);
ResultType ProcessReadData(char *InputData, float Temperature[], float SOC[]);
ResultType FindMovingAverage(float arrayvalue[]);
ResultType readfromConsole(float Temperature[], float SOC[]);
ResultType FindMinandMaxValue(float InputReading[], UserRequestOperation UserRequestOperator)