Basic class structure:

*	All the class declarations are in .h file. 
	It includes the declaration of all variables and functions of the class. 

*	All implementations are in .cpp file.
	include ".h" in the begining. Then there is no need to reclaim the class header again. 
	Directly start implementing functions.
	There are two types of functions, class function and friend function.

*	Class function can directly access the private data of the class.
	eg. return type className::functionName(params){ directly assign values to private variables. }

	Friend functions can get access to the private variables but doesn't belong to the class.
	eg. in .h file, declaire firend functions with keyword "friend":
	friend returntype funcname(params){}
	The function will return a copy of value.

	We also have to declair it outside the class declaration.

*	const and pass by reference:
	Control func params: Use & to pass by reference, but use "const" in front to restrict any value changes. This technique saves space.

	Control func: disallow the member fucntion to modify the object:
	eg. string BigInteger::getNumber() const

*	Operator override:
	Use as friend func. 
	BigInteger operator+(const BigInteger & a, const BigInteger & b);
	istream & operator>>(istream & cin, BigInteger & a);

Compilation process:
*	Preprocessing:
	Preprocessor handles the "\#include, \#define, \#if ... \#enfif, \#ifdef ... \#endif, \#ifndef...\#endif".
	\#define defines a constant variable. eg. \#define PI 3.1415926
	\#if ... \#endif will control execution of lines in between. [example]{./ifendif.cpp}
	
