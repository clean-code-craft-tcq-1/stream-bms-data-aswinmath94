#include <stdio.h>


typedef struct
{
	float min;
	float max;
}minMax_st;

#define MAX_SIZE_TO_READ 400
extern int lengthOfInputData;
void FindMaxValue(float InputReading[]);
void FindMinValue(float InputReading[]);
void ExtractBatteryData_FromInput(char *InputData, float Temperature[], float SOC[]);
void ProcessReadData(char *InputData, float Temperature[], float SOC[]);
void MovingAvg(float arrayvalue[]);
void readfromConsole(float Temperature[], float SOC[]);