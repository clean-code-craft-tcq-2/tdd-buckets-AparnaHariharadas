#include "chargingCurrentRangeCapture.h"

#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string>
#include<array> 
int lastElement= 0;
int maxValues[10] = {0};
int minValues[10] = {0};
int arrayCount[10] = {0};

int checkIfConcurrent(int* arrayOfOccurance){
       int minRange, maxRange = -1;
	int counter, rangeCounter = 0;
	for (int LoopIndex = 0; LoopIndex <= lastElement ; LoopIndex++) {
		if (arrayOfOccurance[LoopIndex]!=0){
			counter += arrayOfOccurance[LoopIndex];
			cout <<" counter "<< counter<<endl ;
			if(minRange == -1){
				minRange = LoopIndex;
				maxRange = LoopIndex;
				cout <<" minRange "<< minRange<<endl ;
			}
			else{
				maxRange = LoopIndex;
			}
		}
		else if (counter != 0){
			minValues[rangeCounter] = minRange;
			maxValues[rangeCounter] = maxRange;
			arrayCount[rangeCounter] = counter;
			cout <<" Minimum "<< minRange <<maxRange <<minValues[rangeCounter]<<endl ;
			minRange = -1;
			maxRange = -1;
			counter = 0;
			rangeCounter++;
			
		}
	}
		return rangeCounter;
}


int* findNumberOfOccurences(int chargingCurrentSamples[], int numberOfSamples){
	int* sampleOccurances;
	lastElement = chargingCurrentSamples[numberOfSamples-1];
	sampleOccurances = (int*)calloc(lastElement, sizeof(int));
	int index =0;
	for (int LoopIndex = 0; LoopIndex < numberOfSamples ; LoopIndex++) {
		index = chargingCurrentSamples[LoopIndex];
		sampleOccurances[index]++;
	}
	
	return sampleOccurances;
}
void printRangeValuestoConsole(int rangeOccurance)
{
	std::ostringstream currentRangeAndOccurance;
	for (int LoopIndex = 0; LoopIndex < rangeOccurance ; LoopIndex++) {
		currentRangeAndOccurance << minValues[rangeOccurance] << "-" << maxValues[rangeOccurance] << "," << arrayCount[rangeOccurance]<<"\n";
		cout << currentRangeAndOccurance.str() << endl;
	}
}

int captureChargingCurrentRange(int chargingCurrentSamples[], int noOfCurrentReadings){
	size_t numberOfSamples;
	numberOfSamples = noOfCurrentReadings;
	sort(chargingCurrentSamples,chargingCurrentSamples+noOfCurrentReadings);
	int* arrayOfOccurances = findNumberOfOccurences(chargingCurrentSamples, numberOfSamples);
	cout <<"initial" <<arrayOfOccurances[4] <<endl ;
	int rangeOccurance = checkIfConcurrent(arrayOfOccurances);
        printRangeValuestoConsole(rangeOccurance);
        return rangeOccurance;
}

