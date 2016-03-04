#include <iostream>

#define DEBUG 1

using namespace std;

int main(){
	#if DEBUG 
		cout << "Debugging!" << endl;
	#endif
	double r;
	cin >> r;
	#if DEBUG
		cout << "The value of r is " << r << endl;
	#endif

	return 0;
}
