#include <iostream>
#include <algorithm>
using namespace std;

int captureChargingCurrentRange (int CurrentSamples[], int noOfCurrentReadings);
int* convertAndCheckAdcValues(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
//signed int* convertAndCheck10BitAdcValues(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
int captureConcurrentADCRanges(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
//int captureConcurrent10BitADCRanges(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings)
