#include <iostream>
using namespace std;

int main(){
	int x = 1;

	decltype(x) y = 2;

	cout << x << endl;
	cout << y << endl;

	return 0;
}