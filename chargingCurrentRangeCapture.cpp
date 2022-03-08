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

int captureChargingCurrentRange(int chargingCurrentSamples[], int noOfCurrentReadings){
	//char *chargingCurrentRangeAndOccurences = (char*)malloc(100);
	int maxValue, minValue, DifferenceBetweenSamples;
	size_t numberOfSamples;
	int numberOfOccurences = 0;

	numberOfSamples = noOfCurrentReadings;
	cout << numberOfSamples <<endl ;
	minValue = findMinValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	maxValue = findMaxValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	for (int LoopIndex = 0; LoopIndex < numberOfSamples ; LoopIndex++) {
		//cout << chargingCurrentSamples[LoopIndex] <<endl ;
		DifferenceBetweenSamples = chargingCurrentSamples[LoopIndex + 1] - chargingCurrentSamples[LoopIndex];
		if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1))
			{
			numberOfOccurences ++;
			}
	}
  std::ostringstream out;  
  out << minValue << maxValue << numberOfOccurences;
  cout << out.str() << endl;
	//sprintf(chargingCurrentRangeAndOccurences, "%d-%d, %lu", minValue, maxValue, numberOfOccurences);
	//cout << chargingCurrentRangeAndOccurences <<endl;//printf("Range, Readings \n");
	//printf("%s\n", chargingCurrentRangeAndOccurences);
return numberOfOccurences;
}





/*int captureChargingCurrentRange (int *CurrentSamples){
  int NumOfCurrentSamples;
  int NumOfConsecutiveRange=0;
  int DifferenceBetweenSamples;
  int LoopIndex;
  int rangeMinValue=0;
  int rangeMaxValue = 0;
  NumOfCurrentSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  cout << NumOfCurrentSamples <<endl ;
  int final_array[NumOfCurrentSamples] = {0};
  //std::sort(CurrentSamples, (CurrentSamples+NumOfCurrentSamples)); 
  for (LoopIndex = 0; LoopIndex<NumOfCurrentSamples ; LoopIndex++) {
    //cout << CurrentSamples[LoopIndex] <<endl ;
    DifferenceBetweenSamples = CurrentSamples[LoopIndex + 1] - CurrentSamples[LoopIndex];
    if((DifferenceBetweenSamples == 0) || (DifferenceBetweenSamples == 1))
    {
      NumOfConsecutiveRange ++;
      final_array[NumOfConsecutiveRange] = CurrentSamples[LoopIndex];
    }
    else
    {
      final_array[NumOfConsecutiveRange] = 0;
      NumOfConsecutiveRange = 0;
    }
  }
  rangeMinValue = final_array[0];
  for (LoopIndex = 0; LoopIndex<NumOfCurrentSamples ; LoopIndex++) {
    //cout << final_array[LoopIndex] <<endl ;
    if (final_array[LoopIndex] == 0)
    {
      rangeMaxValue = final_array[LoopIndex - 1];
    }
    
  }
       //cout << NumOfConsecutiveRange << endl;
       //cout << rangeMinValue << endl;
       //cout << rangeMaxValue << endl;
       return (NumOfConsecutiveRange);//, rangeMinValue, rangeMaxValue);
}*/
