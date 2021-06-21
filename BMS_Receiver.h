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

#define MAX_SIZE_TO_READ 400
#define Find_Min_Value 0
#define Find_Max_Value 1

extern float Temperature[MAX_SIZE_TO_READ];
extern float SOC[MAX_SIZE_TO_READ];
  
extern int lengthOfInputData;
void FindMaxValue(float InputReading[]);
void FindMinValue(float InputReading[]);
void ExtractBatteryData_FromInput(char *InputData, float Temperature[], float SOC[]);
void ProcessReadData(char *InputData, float Temperature[], float SOC[]);
void FindMovingAverage(float arrayvalue[]);
void readfromConsole(float Temperature[], float SOC[]);
void (*FindMinMaxofInput[])(float InputReading[]);