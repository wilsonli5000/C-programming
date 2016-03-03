#include <string>
#include "BigInteger.h"

using namespace std;

//This is the function implementation cpp file. No need to reclaim class headers.
void BigInteger::setNumber(string s){
	//set sign
	if (s[0] == '-'){
		sign = '-';
		s = s.substr(1);
	}
	else
		sign = '+';

	//set length
	length = s.length();

	//set value, reversely set for further use.
	int j = 0;
	for (int i = s.length() - 1; i >= 0; i--)
		value[j++] = s[i] - '0';
}

string BigInteger::getNumber(){
	//output the number
	string number;
	number = number + (sign == '-' ? "-" : "");
	for (int i = length - 1; i >= 0; i--)
		number = number + char(value[i] + '0');
	return number;
}

//friend function doesn't belong to the class.
BigInteger operator+(const BigInteger & a, const BigInteger & b){
	/*four cases: 
	1. both a and b are positive.
	2. both a and b are negative.
	3. a is positive and b is negative
	4. a is negative and b is positive.
	*/
	BigInteger c;
	if (a.sign == '+' && b.sign == '+'){
		//set sign
		c.sign = '+';

		//set value
		int carry = 0, i;
		for (i = 0; i < a.length || i < b,length; i++){
			int tmp = (i < a.length ? a.value[i] : 0) + (i < b.length ? b.value[i] : 0) + carry;
			c.value[i] = tmp % 10;
			carry = tmp / 10;
		}
		if (carry > 0)
			c.value[i++] = carry;
		
		//set length
		c.length = i;
	}
	else if (a.sign == '-' && b.sign == '-'){
		a.sign = '+';
		b.sign = '+';
		c = a + b;
		c.sign = '-';
	}
	else if (a.sign == '+' && b.sign == '-'){
		//set value
		int carry = 0, i;
		for (i = 0; i < a.length || i < b.length; i++){
			//carry is either 0 or -1.
			int tmp = (i < a.length ? a.value[i] : 0) + 10 - (i < b.length ? b.value[i] : 0) + carry;
			c.value[i] = tmp % 10;
			//carry = -1 means borrowed, carry = 0 means not borrowed.
			carry = temp % 10 - 1;
		}
		//set length, get rid of all the 0s in the front. 
		c.length = i;
		while (c.value[c.length - 1] == 0 && c.length > 0)
			c.length--;
		c.length = c.length > 0 ? c.length : 1;
		//check carry bit
		if (carry == 0){
			c.sign = '+';
		}
		else{
			BigInteger d;
			d.sign = '+';
			d.length = i + 1;
			//d is 000001
			for (int j = 0; j < d.length; j++)
				d.value[j] = 0;
			d.value[i] = 1;
			c.sign = '-';
			c = d + c;
			c.sign = '-';
		}
	}
	else if (a.sign == '-' && b.sign == '+'){
		c = b + a;
	}
	return c;
}

istream & operator>>(istream & cin, BigInteger & a){
	string s;
	cin >> s;
	a.setNumber(s);
}

ostream & operator<<(ostream & cout, const BigInteger & a){
	cout << "The number is " << a.getNumber() << endl;
}

BigInteger & operator++(BigInteger & a){
	BigInteger b;
	b.setNumber("1");
	a = a + b;
	return a;
}

BigInteger operator++(BigInteger & a, int usless){
	BigInteger origin = a;
	BigInteger one;
	one.setNumber("1");
	a = a + 1;
	return origin;
}
