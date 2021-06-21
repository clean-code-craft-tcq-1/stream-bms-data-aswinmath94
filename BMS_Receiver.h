#include <stdio.h>

void FindMaxValue(float *InputReading);
void FindMinValue(float *InputReading);
void ExtractBatteryData_FromInput(char *InputData, float *Temperature, float *SOC);
void ProcessReadData(char *InputData, float *Temperature, float *SOC);
void MovingAvg(float *arrayvalue);
void readfromConsole(float *Temperature, float *SOC);