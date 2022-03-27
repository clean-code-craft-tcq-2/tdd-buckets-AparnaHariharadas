#include <iostream>
#include <algorithm>
using namespace std;

int captureChargingCurrentRange (int CurrentSamples[], int noOfCurrentReadings);
int convertAndCheckAdcValues(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
int captureConcurrentADCRanges(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
