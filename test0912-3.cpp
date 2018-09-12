#include "stdafx.h"
#include <iostream>
using namespace std; 
int Absolute(int x);
void main(void)
{

	int a = 3;

	int b = -5;



	a = Absolute(a);

	b = Absolute(b);

	cout << a << endl;

	cout << b << endl;

}
int Absolute (int x) {
	if (x < 0) {
		x = -x;
	}
	return x;
}