#include <iostream>
#include <algorithm>
using namespace std;

int captureChargingCurrentRange (int CurrentSamples[], int noOfCurrentReadings);
int* convertAndCheckTwelveBitAdcValues(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
signed int* convertAndCheckTenBitAdcValues(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
int captureConcurrentADCRanges(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
int ADCRanges(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
