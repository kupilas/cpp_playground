#include <string>
#include <iostream>

using namespace std;


class Person{

	public:
	 string name;
	 

	class Address{
	 	public:
	 		string street;
	 		int houseNumber;
	 };

	 Address address;
};

int main(){

	Person::Address address;
	address.street = "Eiffestr.";
	address.houseNumber = 1;

	Person maniek;
	maniek.address.street = "Somestr.";


	cout << address.houseNumber << endl;
	cout << maniek.address.street << endl;

	return 0;
}