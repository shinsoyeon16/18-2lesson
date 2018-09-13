#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T1>
T1 Square(T1 a) {
	return a * a;
}

int main() {
	cout << Square(3) << endl;
	cout << Square(3.3) << endl;
}