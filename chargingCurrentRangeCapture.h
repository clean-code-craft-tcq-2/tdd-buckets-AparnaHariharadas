#include <iostream>
#include <algorithm>
using namespace std;

int captureChargingCurrentRange (int CurrentSamples[], int noOfCurrentReadings);
int* convertAndCheck12BitAdcValues(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
signed int* convertAndCheck10BitAdcValues(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
int captureConcurrent12BitADCRanges(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings);
int captureConcurrent10BitADCRanges(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings)
