#include "stdafx.h"
#include <iostream>
using namespace std;

// ���۷����� ���� (��������� �ٸ��� ������� �Ŀ��� ���� �Ȱ���)
/*
int main(void) {
	int val = 10;
	int * pVal = &val;
	int &rVal = val;
	cout << &val << endl;
	cout << pVal << endl;
	cout << &rVal << endl;
	return 0;
}
*/

// ���� ����
/*
void Swap(int &a, int &b) {
	int nTmp = a;
	a = b;
	b = nTmp;
}

int _tmain(int argc, _TCHAR* argv[]) {
	int x = 10, y = 20;
	Swap(x, y);

	cout << x << endl;
	cout << y << endl;

	return 0;

}*/

//

int _tmain(int argc, _TCHAR* argv[])
{
	int aList[5] = { 10, 20, 30, 40, 50 };

	// �������� C ��Ÿ�� �ݺ���
	for (int i = 0; i < 5; ++i)
		cout << aList[i] << ' ';

	cout << endl;

	// ���� ��� C++11 ��Ÿ�� �ݺ���
	// �� ����� ���� n�� �����Ѵ�.



	cout << endl;

	// n�� �� ��ҿ� ���� ������.



	cout << endl;

	return 0;
} 