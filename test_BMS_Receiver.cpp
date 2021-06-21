#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "BMS_Receiver.h"


/*Positive test case */
TEST_CASE("Case for Postive test case :- Success of Data readFromConsole") {

  REQUIRE(readfromConsole(Temperature, SOC) == success);
}
/*Positive test case */
TEST_CASE("Case for Positive test case :-Success of finding temperature array Minimum value") {
  REQUIRE((*FindMinMaxofInput[Find_Min_Value])(Temperature) == success);
  REQUIRE(minMax_data.min != 0);
}

/*Positive test case */
TEST_CASE("Case for Positive test case :-Success of finding SOC array Minimum value") {
  REQUIRE((*FindMinMaxofInput[Find_Min_Value])(SOC) == success);
  REQUIRE(minMax_data.min != 0);
}

/*Positive test case */
TEST_CASE("Case for Positive test case:-Success of finding SOC array Maximum value value") {
  REQUIRE((*FindMinMaxofInput[Find_Max_Value])(SOC) == success);
  REQUIRE(minMax_data.max != 0);
}

TEST_CASE("Case for evaluating success of Moving average of temperature") {

  REQUIRE(FindMovingAverage(Temperature) == success);
}

TEST_CASE("Case for evaluating success of Moving average of SOC") {

  REQUIRE(FindMovingAverage(SOC) == success);
}

