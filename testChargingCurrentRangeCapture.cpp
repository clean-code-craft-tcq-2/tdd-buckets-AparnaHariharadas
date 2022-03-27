#define CATCH_CONFIG_MAIN 

#include "test-framework/catch.hpp"
#include "chargingCurrentRangeCapture.h"

TEST_CASE("Checks the charging current ranges and captures the no of occurences") {
  int CurrentRanges[] = {4,5};
  int noOfcurrentReadings = sizeof(CurrentRanges)/sizeof(CurrentRanges[0]);
  REQUIRE(captureChargingCurrentRange(CurrentRanges, noOfcurrentReadings) == 1);
  int CurrentRangesnew[6] = {3,3,4,4,5,6};
  noOfcurrentReadings = sizeof(CurrentRangesnew)/sizeof(CurrentRangesnew[0]);
  REQUIRE(captureChargingCurrentRange(CurrentRangesnew, noOfcurrentReadings) == 1);
  int CurrentRangeslatestvalue[10] = {3,4,5,6,7,8,10,11,12};
  noOfcurrentReadings = sizeof(CurrentRangeslatestvalue)/sizeof(CurrentRangeslatestvalue[0]);
  REQUIRE(captureChargingCurrentRange(CurrentRangeslatestvalue, noOfcurrentReadings) == 2);

}
