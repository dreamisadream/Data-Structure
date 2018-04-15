#include "KMP.h"

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

KMP::KMP(int _TextSize, int _PatternSize)
{
    //set Text & Pattern
    Text = new char[_TextSize];
    Pattern = new char[_PatternSize];

    cout << "Text: ";
    cin >> Text;

    cout << "Pattern: ";
    cin >> Pattern;
}


KMP::~KMP()
{
  delete [] Text;
  delete [] Pattern;
}


int KMP::stringCompare()
{
  //set failure array
  int Plen = strlen(Pattern);
  int failureArray[Plen];

  failureArray[0] = 0;
  for(int i = 1; i<Plen; i++){
    if(Pattern[i] == Pattern[ failureArray[i-1] ])
      failureArray[i] = failureArray[i-1]+1;
    else
      failureArray[i] = 0;
  }

  //comparing
  char *Tptr = Text;
  char *Pptr = Pattern;
  int Tlen = strlen(Text);

  for(int i = 0; i<Tlen; i++){
    if(*Tptr == *Pptr){
      if(Pptr == &Pattern[Plen-1]) //found
        return i+1-Plen;
      Tptr++;
      Pptr++;
    }//end of if
    else{
      if(Pptr == Pattern){
        Tptr++;
      }
      else{
      int pos = Pptr - Pattern;
      Pptr = Pattern + failureArray[pos-1];
      i--; // compare same char
      }
    }//end of else
  } //end of for

  return -1;
}
