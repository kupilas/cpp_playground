#include <iostream>
using namespace std;


template <class AnyType>
void printThem(AnyType &a, AnyType &b) {
	cout << a << endl;
	cout << b << endl;
}

int main(){

	int a = 1;
	char c = 'a';

	printThem(a, a);
	printThem(c, c);

	return 0;
}