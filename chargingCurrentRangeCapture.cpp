#include "chargingCurrentRangeCapture.h"

#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string>
#include<array> 
int numberOfOccurences[5], minValue[5], maxValue[5] = {0};
int counter= 0;
int findMinValueOfChargingCurrentRange(int* chargingCurrentSamples, int numberOfSamples){
	minValue = chargingCurrentSamples[numberOfSamples-1]; //Initializing to last element  
	for (int i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] < minValue){
			minValue[counter] = chargingCurrentSamples[i];
		}
	}
	return minValue;
}

int findMaxValueOfChargingCurrentRange(int* chargingCurrentSamples, int numberOfSamples){
	maxValue = chargingCurrentSamples[0]; // Initializing to first element
	for (int i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] > maxValue){
			maxValue[counter] = chargingCurrentSamples[i];
		}
	}
	return maxValue;
}

void checkIfConcurrent(int DifferenceBetweenSamples, int currentmaxValue, int nextMinValue){
        numberOfOccurences = numberOfOccurences + checkIfConcurrent(DifferenceBetweenSamples);
	if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1))
		numberOfOccurences[counter] = numberOfOccurences[counter] + 1;
			
	else{
		counter = counter + 1;
		maxValue[counter] = currentmaxValue;
	        minValueNext[counter] = nextMinValue;
		numberOfOccurences[counter] = 0;
	}
}


void findNumberOfOccurences(int chargingCurrentSamples[], int numberOfSamples){
	for (int LoopIndex = 0; LoopIndex < numberOfSamples ; LoopIndex++) {
		DifferenceBetweenSamples = chargingCurrentSamples[LoopIndex + 1] - chargingCurrentSamples[LoopIndex];
		checkIfConcurrent(DifferenceBetweenSamples, chargingCurrentSamples[LoopIndex], chargingCurrentSamples[LoopIndex + 1]);
	}
	
}


int captureChargingCurrentRange(int chargingCurrentSamples[], int noOfCurrentReadings){
	int maxValue, minValue;
	size_t numberOfSamples;
	int numberOfOccurencesFinal = 0;

	numberOfSamples = noOfCurrentReadings;
	cout << numberOfSamples <<endl ;
	minValue = findMinValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	maxValue = findMaxValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	findNumberOfOccurences(chargingCurrentSamples, numberOfSamples);
	
        std::ostringstream currentRangeAndOccurance;
	for (int LoopIndex = 0; LoopIndex < 5 ; LoopIndex++) {
        currentRangeAndOccurance << minValue[LoopIndex] << "-" << maxValue[LoopIndex] << "," << numberOfOccurences[LoopIndex];
        cout << currentRangeAndOccurance.str() << endl;
	}
        return numberOfOccurences;
}

