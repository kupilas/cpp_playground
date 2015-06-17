#include <iostream>
#include "Guitar.h"

using namespace std;


Guitar::Guitar()
{
  cout << "creating guitar object" << endl;
  numberOfStrings = 3;
  cout << this->getNumberOfStrings() << endl;
  
}

Guitar::~Guitar()
{
}

int Guitar::getNumberOfStrings()
{
  return numberOfStrings;
}

int Guitar::n = 555;