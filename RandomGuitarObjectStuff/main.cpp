#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>

#include "b/test.h" 
#include "Guitar.h" 

using namespace std;

inline void test(int& a){
  a++;
}

// void abcPrototyp();

int main()
{

  int testA = INT_MAX;
 
  abcPrototyp();
  cout << testA << endl;

/**
  cout << "Enter price: ";
  getline (cin,mystr);
  stringstream(mystr) >> price;
  cout << "Enter quantity: ";
  getline (cin,mystr);
  stringstream(mystr) >> quantity;
  cout << "Total price: " << price*quantity << endl;
  return 0;
  **/
}

void abcPrototyp(){
  printf("abc \n");

  Guitar guitar;
  cout << guitar.getNumberOfStrings() << " " << Guitar::n << endl;
  
}
