using namespace std;

class BigInteger{
	private: 
		char sign;
		int length;
		//here the upper bound of length is 100 digits.
		int value[100];
	public:
		void setNumber(string s);
		string getNumber() const;
		//friend BigInteger add(const BigInteger & a, const BigInteger & b);
		friend BigInteger operator+(const BigInteger & a, const BigInteger & b);
		friend istream & operator>>(istream & cin, BigInteger & a);
		friend ostream & operator<<(ostream & cout, const BigInteger & a);
		//this is prefix increament
		friend BigInteger & operator++(BigInteger & a);
		//this is postfix increment, the second parameter is just for distinguishment.
		friend BigInteger operator++(BigInteger & a, int usless);
};

BigInteger operator+(const BigInteger & a, const BigInteger & b);
istream & operator>>(istream & cin, BigInteger & a);
ostream & operator<<(ostream & cout, const BigInteger & a);
BigInteger & operator++(BigInteger & a);
BigInteger operator++(BigInteger & a, int usless);

