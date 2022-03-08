#include "chargingCurrentRangeCapture.h"


int captureChargingCurrentRange (int *CurrentSamples){
  int NumOfCurrentSamples;
  int NumOfConsecutiveRange=0;
  int DifferenceBetweenSamples;
  int LoopIndex;
  int rangeMinValue=0;
  int rangeMaxValue = 0;
  NumOfCurrentSamples = sizeof(CurrentSamples)/sizeof(CurrentSamples[0]);
  cout << NumOfCurrentSamples <<endl ;
  int final_array[NumOfCurrentSamples] = {0};
  std::sort(CurrentSamples, (CurrentSamples+NumOfCurrentSamples)); 
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
    cout << final_array[LoopIndex] <<endl ;
    if (final_array[LoopIndex] == 0)
    {
      rangeMaxValue = final_array[LoopIndex - 1];
    }
    
  }
       //cout << NumOfConsecutiveRange << endl;
       //cout << rangeMinValue << endl;
       //cout << rangeMaxValue << endl;
       return (NumOfConsecutiveRange);//, rangeMinValue, rangeMaxValue);
}
