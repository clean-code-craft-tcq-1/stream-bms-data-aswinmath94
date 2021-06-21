#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
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
TEST_CASE("Case for Positive test case:-Success of finding SOC array Maximum value value") {
  UserRequestOperation Operator= ToFindMaxValue;
  REQUIRE(FindMinandMaxValue(SOC,Operator)  == Success);
}

TEST_CASE("Case for evaluating success of Moving average of temperature") {

  REQUIRE(FindMovingAverage(Temperature) == Success);
}

TEST_CASE("Case for evaluating success of Moving average of SOC") {

  REQUIRE(FindMovingAverage(SOC) == Success);
}

