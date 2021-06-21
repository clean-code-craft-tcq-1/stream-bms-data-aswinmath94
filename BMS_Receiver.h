#include <stdio.h>


typedef struct
{
	float min;
	float max;
}minMax_st;

extern int lengthOfInputData;
void FindMaxValue(float InputReading[]);
void FindMinValue(float InputReading[]);
void ExtractBatteryData_FromInput(char *InputData, float Temperature[], float SOC[]);
void ProcessReadData(char *InputData, float Temperature[], float SOC[]);
void MovingAvg(float arrayvalue[]);
void readfromConsole(float Temperature[], float SOC[]);