#include <iostream>
#include <string>
#include "BigInteger.h"

using namespace std;

int main(){
	BigInteger a;
	cout << "Please enter a long number: ";
	string s;
	cin >> s;

	a.setNumber(s);

	//output number
	cout << "The number is " << a.getNumber() << endl;
	
	return 0;
}