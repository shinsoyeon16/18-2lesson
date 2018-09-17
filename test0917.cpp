#include "stdafx.h"
#include <iostream>
using namespace std; 

void main()
{
	int * p = new int;

	*p = 1;

	cout << p << endl;

	delete p;
}

int main()
{
	int count = 100;

	int * p = new int[count];

	for (int i = 0; i < count; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < count; i++)
	{
		cout << p[i] << endl;
	}
	delete []p;
}