#include "chargingCurrentRangeCapture.h"

#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string>
#include<array> 

int findMinValueOfChargingCurrentRange(int* chargingCurrentSamples, int numberOfSamples){
	int minValue;
	minValue = chargingCurrentSamples[numberOfSamples-1]; //Initializing to last element  
	for (int i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] < minValue){
			minValue = chargingCurrentSamples[i];
		}
	}
	return minValue;
}

int findMaxValueOfChargingCurrentRange(int* chargingCurrentSamples, int numberOfSamples){
	int maxValue;
	maxValue = chargingCurrentSamples[0]; // Initializing to first element
	for (int i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] > maxValue){
			maxValue = chargingCurrentSamples[i];
		}
	}
	return maxValue;
}

int findNumberOfOccurences(chargingCurrentSamples, numberOfSamples){
	int DifferenceBetweenSamples;
	for (int LoopIndex = 0; LoopIndex < numberOfSamples ; LoopIndex++) {
		DifferenceBetweenSamples = chargingCurrentSamples[LoopIndex + 1] - chargingCurrentSamples[LoopIndex];
		numberOfOccurences = numberOfOccurences + checkIfConcurrent(DifferenceBetweenSamples);
	}
}

int checkIfConcurrent(int DifferenceBetweenSamples){
	if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1))
		return 1;
			
	else
		return 0;
}

int captureChargingCurrentRange(int chargingCurrentSamples[], int noOfCurrentReadings){
	int maxValue, minValu;
	size_t numberOfSamples;
	int numberOfOccurences = 0;

	numberOfSamples = noOfCurrentReadings;
	cout << numberOfSamples <<endl ;
	minValue = findMinValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	maxValue = findMaxValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	numberOfOccurences = findNumberOfOccurences(chargingCurrentSamples, numberOfSamples);
	
        std::ostringstream currentRangeAndOccurance;  
        currentRangeAndOccurance << minValue << "-" << maxValue << "," << numberOfOccurences;
        cout << currentRangeAndOccurance.str() << endl;
        return numberOfOccurences;
}

