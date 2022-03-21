#include "chargingCurrentRangeCapture.h"

#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string>
#include<array> 
int numberOfOccurences[5], minValue[5], maxValue[5] = {0};
int counter= 0;
void findMinValueOfChargingCurrentRange(int* chargingCurrentSamples, int numberOfSamples){
	minValue[counter] = chargingCurrentSamples[numberOfSamples-1]; //Initializing to last element  
	for (int i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] < minValue[counter]){
			minValue[counter] = chargingCurrentSamples[i];
		}
	}
	
}

void findMaxValueOfChargingCurrentRange(int* chargingCurrentSamples, int numberOfSamples){
	maxValue[counter] = chargingCurrentSamples[0]; // Initializing to first element
	for (int i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] > maxValue[counter]){
			maxValue[counter] = chargingCurrentSamples[i];
		}
	}

}

void checkIfConcurrent(int DifferenceBetweenSamples, int currentmaxValue, int nextMinValue){
       	if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1))
		numberOfOccurences[counter] = numberOfOccurences[counter] + 1;
			
	else{
		counter = counter + 1;
		maxValue[counter] = currentmaxValue;
	        minValue[counter] = nextMinValue;
		numberOfOccurences[counter] = 0;
	}
}


void findNumberOfOccurences(int chargingCurrentSamples[], int numberOfSamples){
	int DifferenceBetweenSamples = 0;
	for (int LoopIndex = 0; LoopIndex < numberOfSamples ; LoopIndex++) {
		DifferenceBetweenSamples = chargingCurrentSamples[LoopIndex + 1] - chargingCurrentSamples[LoopIndex];
		checkIfConcurrent(DifferenceBetweenSamples, chargingCurrentSamples[LoopIndex], chargingCurrentSamples[LoopIndex + 1]);
	}
	
}


int captureChargingCurrentRange(int chargingCurrentSamples[], int noOfCurrentReadings){
	size_t numberOfSamples;
	numberOfSamples = noOfCurrentReadings;
	cout << numberOfSamples <<endl ;
	findMinValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	findMaxValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	findNumberOfOccurences(chargingCurrentSamples, numberOfSamples);
	
        std::ostringstream currentRangeAndOccurance;
	for (int LoopIndex = 0; LoopIndex < 5 ; LoopIndex++) {
        currentRangeAndOccurance << minValue[LoopIndex] << "-" << maxValue[LoopIndex] << "," << numberOfOccurences[LoopIndex];
        cout << currentRangeAndOccurance.str() << endl;
	}
        return numberOfOccurences[0];
}

