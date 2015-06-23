#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class A{
public:
  virtual void printStuff()
  {
    cout << "A" << endl;
  }
};

class B : public A{
public:
  void printStuff()
  {
    cout << "B" << endl;
  }
};
void makeItPrint(A *a)
{
  a->printStuff();
}

inline void test(int& a){
  a++;
}

int main()
{
  // int b = 5;
  // test(b);

  // cout << b << endl;

  A *a = new A;
  A *b = new B;
  makeItPrint(a);
  makeItPrint(b);

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
