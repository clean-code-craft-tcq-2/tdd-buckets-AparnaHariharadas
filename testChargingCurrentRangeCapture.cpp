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
  int CurrentRangeslatestvalue[10] = {3,4,5,6,7,8,10,11,12,13};
  noOfcurrentReadings = sizeof(CurrentRangeslatestvalue)/sizeof(CurrentRangeslatestvalue[0]);
  REQUIRE(captureChargingCurrentRange(CurrentRangeslatestvalue, noOfcurrentReadings) == 2);
}

TEST_CASE("Checks 12 bit ADcinput") {
  int CurrentRanges[] = {600,800,950,1000,1200};
  int noOfcurrentReadings = sizeof(CurrentRanges)/sizeof(CurrentRanges[0]);
  int* ptr =convertAndCheck12BitAdcValues(CurrentRanges, noOfcurrentReadings);
  REQUIRE(ptr[0]==1);
  int CurrentRangesnew[] = {600,800,950,1000,1200,5000};
  noOfcurrentReadings = sizeof(CurrentRangesnew)/sizeof(CurrentRangesnew[0]);
  REQUIRE(convertAndCheck12BitAdcValues(CurrentRangesnew, noOfcurrentReadings) == NULL);
 
}

TEST_CASE("Checks 12 bit ADcinput and find ADC range") {
  int CurrentRanges[] = {600,800,950,1000,1200};
  int noOfcurrentReadings = sizeof(CurrentRanges)/sizeof(CurrentRanges[0]);
  REQUIRE(captureConcurrent12BitADCRanges(CurrentRanges, noOfcurrentReadings) == 1);
}
TEST_CASE("Checks 10 bit ADcinput") {
  int CurrentRanges[] = {0,511,1022};
  int noOfcurrentReadings = sizeof(CurrentRanges)/sizeof(CurrentRanges[0]);
  int* ptr =convertAndCheck10BitAdcValues(CurrentRanges, noOfcurrentReadings);
  REQUIRE(ptr[0]==0);
  int CurrentRangesnew[] = {0,511,2000};
  noOfcurrentReadings = sizeof(CurrentRangesnew)/sizeof(CurrentRangesnew[0]);
  REQUIRE(convertAndCheck10BitAdcValues(CurrentRangesnew, noOfcurrentReadings) == NULL);
 
}

TEST_CASE("Checks 10 bit ADcinput and find ADC range") {
  int CurrentRangesnew[] = {0,511,1022};
  int noOfcurrentReadings = sizeof(CurrentRangesnew)/sizeof(CurrentRangesnew[0]);
  REQUIRE(captureConcurrent10BitADCRanges(CurrentRangesnew, noOfcurrentReadings) == 1);
}
