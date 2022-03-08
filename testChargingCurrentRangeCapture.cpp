#define CATCH_CONFIG_MAIN 

#include "test-framework/catch.hpp"
#include "chargingCurrentRangeCapture.h"

TEST_CASE("Checks the charging current ranges and captures the no of occurences") {
  int CurrentRanges[] = {4,5};
  REQUIRE(captureChargingCurrentRange(CurrentRanges) == 1);
  CurrentRanges[] = {3,3,4,4,5,6};
  REQUIRE(captureChargingCurrentRange(CurrentRanges) == 4);
}

