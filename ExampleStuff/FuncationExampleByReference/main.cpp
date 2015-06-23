// g++ main.cpp -o o.out -std=c++0x

#include <iostream>
using namespace std;

void funcationExampleByReference(int& i, int i2 = 2);

int main(){

	int a = 5;
	funcationExampleByReference(a);
	funcationExampleByReference(a, 8);
	cout << a << endl;

	return 0;
}

void funcationExampleByReference(int& i, int i2){ // default value was already set in prototype
	i++;
	cout << i2 << endl; // default value example
}