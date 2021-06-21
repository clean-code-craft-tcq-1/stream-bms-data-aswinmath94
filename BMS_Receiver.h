#include <stdio.h>

void FindMaxValue(float *InputReading, int numberOfReadings);
void FindMinValue(float *InputReading, int numberOfReadings);
void ExtractBatteryData_FromInput(char *InputData, float *Temperature, float *SOC);
void ProcessReadData(char *InputData, float *Temperature, float *SOC);
void MovingAvg(float *arrayvalue,int arraySize);
void readfromConsole(float *Temperature, float *SOC);