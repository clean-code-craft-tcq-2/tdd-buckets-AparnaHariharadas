#include "chargingCurrentRangeCapture.h"

#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string.h>
#include <stdlib.h>
#include<array>
#include<math.h>
#include <algorithm>
#include <iterator>
int lastElement= 0;
int maxValues[50] = {0};
int minValues[50] = {0};
int arrayCount[50] = {0};

int checkIfConcurrent(int* arrayOfOccurance){
       int minRange = -1;
	int maxRange = -1;
	int counter = 0;
	int rangeCounter = 0;
	for (int LoopIndex = 0; LoopIndex < 50 ; LoopIndex++) 
	{
		if(arrayOfOccurance[LoopIndex]!=0)
		{
			counter += arrayOfOccurance[LoopIndex];
			
			if(minRange == -1)
			{
				minRange = LoopIndex;
				maxRange = LoopIndex;
			}
			else
			{
				maxRange = LoopIndex;
			}
		}
		else if(counter != 0)
		{
			minValues[rangeCounter] = minRange;
			maxValues[rangeCounter] = maxRange;
			arrayCount[rangeCounter] = counter;
			minRange = -1;
			maxRange = -1;
			counter = 0;
			rangeCounter++;
			cout <<" rangeCounter "<< rangeCounter <<endl ;
			
		}
	}
		return rangeCounter;
}


int* findNumberOfOccurences(int chargingCurrentSamples[], int numberOfSamples){
	int* sampleOccurances;
	lastElement = chargingCurrentSamples[numberOfSamples-1];
	sampleOccurances = (int*)calloc(50, sizeof(int));
	int index =0;
	for (int LoopIndex = 0; LoopIndex < numberOfSamples ; LoopIndex++) {
		index = chargingCurrentSamples[LoopIndex];
		sampleOccurances[index]++;
	}
	
	return sampleOccurances;
}
void printRangeValuestoConsole(int rangeOfOccurance)
{
	std::ostringstream currentRangeAndOccurance;
	for (int LoopIndex = 0; LoopIndex < rangeOfOccurance ; LoopIndex++) {
		currentRangeAndOccurance << minValues[LoopIndex] << "-" << maxValues[LoopIndex] << "," << arrayCount[LoopIndex]<<"\n";
		cout << currentRangeAndOccurance.str() << endl;
	}
}

int captureChargingCurrentRange(int chargingCurrentSamples[], int noOfCurrentReadings){
	size_t numberOfSamples;
	numberOfSamples = noOfCurrentReadings;
	sort(chargingCurrentSamples,chargingCurrentSamples+noOfCurrentReadings);
	cout <<"chargingCurrentSamples at index  0: " << chargingCurrentSamples[0]<<endl;
	int* arrayOfOccurances = findNumberOfOccurences(chargingCurrentSamples, numberOfSamples);
	cout <<"arrayOfOccurances at index  0: " << arrayOfOccurances[0]<<endl;
	int rangeOfOccurance = checkIfConcurrent(arrayOfOccurances);
        printRangeValuestoConsole(rangeOfOccurance);
        return rangeOfOccurance;
}

int* convertAndCheckAdcValues(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings)
{
	int* ampere;
	ampere = (int*)calloc(50, sizeof(int));
	float adcValuebeforeCeling;
	for(int index = 0;index < noOfAdcCurrentReadings;index++)
	{
		adcValuebeforeCeling = (10 * chargingAdcCurrentSamples[index]) / 4094;
		if(adcValuebeforeCeling > 10 || adcValuebeforeCeling < 0)
		{
			cout <<"current Out of Range at index  : " << index<<endl;
			return NULL;
		}else{
		ampere[index] = ceil(adcValuebeforeCeling);
		}
	}
	return ampere;
}
int captureConcurrentADCRanges(int chargingAdcCurrentSamples[], int noOfAdcCurrentReadings)
{
	int* adcArray = convertAndCheckAdcValues(chargingAdcCurrentSamples,noOfAdcCurrentReadings);
	int adcConvertArray[50];
	cout <<"adcArray at index  0: " << adcArray[0]<<endl;
	memcpy(adcConvertArray, adcArray, 50);
	cout <<"adcConvertArray at index  0: " << adcConvertArray[0]<<endl;
	int rangeOfAdcOccurances  = captureChargingCurrentRange(adcConvertArray,noOfAdcCurrentReadings);
	return rangeOfAdcOccurances;
}

