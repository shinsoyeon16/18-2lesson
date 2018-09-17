#include "stdafx.h"
#include <iostream>
using namespace std;

// 레퍼런스와 변수 (생성방법만 다르고 만들어진 후에는 완전 똑같음)
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

// 스왑 예제
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

	// 전형적인 C 스타일 반복문
	for (int i = 0; i < 5; ++i)
		cout << aList[i] << ' ';

	cout << endl;

	// 범위 기반 C++11 스타일 반복문
	// 각 요소의 값을 n에 복사한다.



	cout << endl;

	// n은 각 요소에 대한 참조다.



	cout << endl;

	return 0;
} 