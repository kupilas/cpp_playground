#include <string>
#include <iostream>

using namespace std;

class SomeAbstractClass{
	virtual void someFunction() = 0;
};


class Person{

	public:
	 Person(int a){
		cout << "Person contructor with: " << a << endl;
	}

	void methodA(int a)
	{
		cout << "methodA with: " << a << endl;
	}

};

class Dude : public Person{

	public:
		Dude(int b) : Person(b){
			cout << "Dude constructor with: " << b << endl;
		}

		void methodA(int a)
		{
			Person::methodA(a);
			cout << "overriden methodA with: " << a << endl;
		}

};

int main(){

	Dude maniek(1);
	maniek.methodA(5);
	maniek.Person::methodA(5);

	return 0;
}