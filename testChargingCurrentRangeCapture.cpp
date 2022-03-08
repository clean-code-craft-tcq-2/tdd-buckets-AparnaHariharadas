#define CATCH_CONFIG_MAIN 

#include "test-framework/catch.hpp"
#include "chargingCurrentRangeCapture.h"

TEST_CASE("Checks the charging current ranges and captures the no of occurences") {
  int CurrentRanges[] = {4,5};
  REQUIRE(captureChargingCurrentRange(CurrentRanges) == 1);
  int CurrentRangesnew[6] = {3,3,4,4,5,6};
  REQUIRE(captureChargingCurrentRange(CurrentRangesnew) == 5);
   int CurrentRangeslatest[6] = {3,4,5,6,7,8};
  REQUIRE(captureChargingCurrentRange(CurrentRangeslatest) == 5);

}

