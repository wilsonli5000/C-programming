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

	BigInteger b;
	cout << "Please enter a long number: ";
	cin >> s;
	b.setNumber(s);

	BigInteger c = a + b;

	//output number
	cout << "The sum is " << c << endl;
	
	return 0;
}