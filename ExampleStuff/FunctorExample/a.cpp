#include <iostream>

using namespace std;


// dmmy functor example
// A functor is pretty much just a class which defines the operator(). That lets you create objects which "look like" a function:

class FunctorTest{
public:
	void operator()(int i){
		cout << i << endl;
	}
};

int main(){
	FunctorTest abc; // create instance
	abc(2); // use it

	FunctorTest()(1); 

	return 0;
}

