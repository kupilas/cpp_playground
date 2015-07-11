#include <string>
#include <iostream>

using namespace std;


class Person{

	public:
	 Person(int a){
		cout << "Person contructor with: " << a << endl;
	}

};

class Dude : public Person{

	public:
		Dude(int b) : Person(b){
			cout << "Dude constructor with: " << b << endl;
		}

};

int main(){

	Dude maniek(1);

	return 0;
}