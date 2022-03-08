#include "chargingCurrentRangeCapture.h"

#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string>

char* captureChargingCurrentRange(int* chargingCurrentSamples){
	char *chargingCurrentRangeAndOccurences = (char*)malloc(100);
	int maxValue, minValue;
	size_t numberOfSamples, numberOfOccurences;

	numberOfSamples = findNumberOfSamples(chargingCurrentSamples);
	minValue = findMinValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	maxValue = findMaxValueOfChargingCurrentRange(chargingCurrentSamples, numberOfSamples);
	numberOfOccurences = numberOfSamples; // Since input is conidered as a single range
  std::ostringstream out;  
  out << minValue << maxValue << numberOfOccurences;
  cout << out.str() << endl;
	//sprintf(chargingCurrentRangeAndOccurences, "%d-%d, %lu", minValue, maxValue, numberOfOccurences);
	//cout << chargingCurrentRangeAndOccurences <<endl;//printf("Range, Readings \n");
	//printf("%s\n", chargingCurrentRangeAndOccurences);
	return chargingCurrentRangeAndOccurences;
}

size_t findNumberOfSamples(int* chargingCurrentSamples) {
	size_t numberOfSamples;
	numberOfSamples = sizeof(chargingCurrentSamples) / sizeof(chargingCurrentSamples[0]);
	return numberOfSamples;
}

int findMinValueOfChargingCurrentRange(int* chargingCurrentSamples, size_t numberOfSamples){
	int minValue;
	minValue = chargingCurrentSamples[numberOfSamples-1]; //Initializing to last element  
	for (size_t i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] < minValue){
			minValue = chargingCurrentSamples[i];
		}
	}
	return minValue;
}

int findMaxValueOfChargingCurrentRange(int* chargingCurrentSamples, size_t numberOfSamples){
	int maxValue;
	maxValue = chargingCurrentSamples[0]; // Initializing to first element
	for (size_t i=0; i<numberOfSamples; i++) {
		if(chargingCurrentSamples[i] > maxValue){
			maxValue = chargingCurrentSamples[i];
		}
	}
	return maxValue;
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
