#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMS_Receiver.h"


/*Positive test case */
TEST_CASE("Case for Postive test case :- Success of Data readFromConsole") {

  REQUIRE(readfromConsole(Temperature, SOC) == Success);
}
/*Positive test case */
TEST_CASE("Case for Positive test case :-Success of finding temperature array Minimum value") {
	UserRequestOperation Operator= ToFindMinValue;
    REQUIRE(FindMinandMaxValue(Temperature,Operator) == Success);
}

/*Positive test case */
TEST_CASE("Case for Positive test case :-Success of finding SOC array Minimum value") {
  UserRequestOperation Operator= ToFindMinValue;
  REQUIRE(FindMinandMaxValue(SOC,Operator) == Success);
}

/*Positive test case */
TEST_CASE("Case for Positive test case:-Success of finding Temperature array Maximum value value") {
  UserRequestOperation Operator= ToFindMaxValue;
  REQUIRE(FindMinandMaxValue(Temperature,Operator )  == Success);
}

/*Positive test case */
TEST_CASE("Case for Positive test case:-Success of finding SOC array Maximum value value") {
  UserRequestOperation Operator= ToFindMaxValue;
  REQUIRE(FindMinandMaxValue(SOC,Operator)  == Success);
}

TEST_CASE("Case for evaluating success of Moving average of temperature") {

  REQUIRE(FindMovingAverage(Temperature,lengthOfInputData) == Success);
}

TEST_CASE("Case for evaluating success of Moving average of SOC") {

  REQUIRE(FindMovingAverage(SOC,lengthOfInputData) == Success);
}

TEST_CASE("Case for evaluating Printing to console:Temperature:Minimum,Maximum, Moving Average") 
{
	float OutputAveragearray[lengthOfInputData]={};
	PrintingData DataToPrint;
	DataToPrint.UserRequestOperator= ToFindMinValue;
	DataToPrint.IndexOfBatteryMessage= TEMPERATURE;
	DataToPrint.LengthOfAvgArray=lengthOfInputData;
	REQUIRE(FindMinandMaxValue(Temperature,DataToPrint.UserRequestOperator) == Success);
	DataToPrint.UserRequestOperator= ToFindMaxValue;
	REQUIRE(FindMinandMaxValue(Temperature,DataToPrint.UserRequestOperator) == Success);
    REQUIRE(FindMovingAverage(Temperature,DataToPrint.LengthOfAvgArray,OutputAveragearray) == Success);
    REQUIRE(PrintToConsole(OutputAveragearray,DataToPrint) == Success);
}

TEST_CASE("Case for evaluating Printing to console:SOC:Minimum,Maximum, Moving Average") 
{
	float OutputAveragearray[lengthOfInputData]={};
	PrintingData DataToPrint;
	DataToPrint.UserRequestOperator= ToFindMinValue;
	DataToPrint.IndexOfBatteryMessage= STATEOFCHARGE;
	DataToPrint.LengthOfAvgArray=lengthOfInputData;
    REQUIRE(FindMinandMaxValue(SOC,DataToPrint.UserRequestOperator) == Success);
	DataToPrint.UserRequestOperator= ToFindMaxValue;
    REQUIRE(FindMovingAverage(SOC,DataToPrint.LengthOfAvgArray,OutputAveragearray) == Success);
    REQUIRE(PrintToConsole(OutputAveragearray,DataToPrint) == Success);
}