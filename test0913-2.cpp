#include "stdafx.h"
#include <iostream>
using namespace std;
void Set(char* s);

int main() {
	int a = 0;
	char * s = (char*)&a;
	Set(s);
	cout << (char*)&a << endl;
}
void Set(char* s) {
	*s = 'C';
	*(s + 1) = '+';
	*(s + 2) = *(s + 1);
}