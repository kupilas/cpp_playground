#include <iostream>
#include <vector> 

using namespace std;

int main(){

	auto func = [] () { cout << "Hello world" << endl; };
    func(); // now call the function

    int number = 5;
    auto func2 = [&] () { cout << "number: " << number << endl; };
    func2();

    vector<int> v;
	v.push_back( 1 );
	v.push_back( 2 );

	// for each without lambda
	for ( auto itr = v.begin(), end = v.end(); itr != end; itr++ ){
    cout << *itr << endl;
	}

	// for each example with lambda and stl lib
	for_each(v.begin(), v.end(), [](int val){
 	   cout << val << endl;
	} );


	///////////////////
	///////////////////
	///////////////////
	

	auto returnFuncExample = [] () { 
		return 1; 
	}; // compiler knows this returns an integer
	int number2 = returnFuncExample();

	auto returnExampl2 = [] () -> int { 
		return 1; // compiler knows this returns an integer
	}; 
	int number3 = returnExampl2();

	cout << number2 << " : " << number3 << endl;

	return 0;
}

