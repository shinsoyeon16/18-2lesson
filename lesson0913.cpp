#include "stdafx.h"
#include <iostream>
using namespace std;

/* 
void buy(int a = 200);
int main() {
	buy(100);
}
void buy(int a) {
	cout << a << endl;
}
*/

// 메소드 오버로딩 예제
/*
int max(int x, int y) {
	if (x > y) { return x; }
	else { return y; }
}
int max(int x, int y, int z) {
	if (x > y && x>z) { return x; }
	else if(y>x && y>z) { return y; }
	else { return z; }
}
double max(double x, double y) {
	if (x > y) { return x; }
	else { return y; }
}

int main() {
	int a, b, c;
	double da, db;
	cout << "3개 입력" << endl;
	cin >> a >> b >> c;
	cout << "소수 2개 입력" << endl;
	cin >> da >> db;
	int res1 = max(a, b);
	int res2 = max(a, b, c);
	double res3 = max(da, db);
	
	cout << res1 << endl;
	cout << res2 << endl;
	cout << res3 << endl;
}
*/

// 함수 템플릿 예제
/*
template <typename T1, typename T2> // 함수 템플릿 정의
void ShowData(T1 a, T2 b) {
	cout << a << " ";
	cout << b << endl;
}

int main() {
	ShowData(1, 2);
	ShowData(3, 2.5);
	ShowData(3.3, 4.3);
	return 0;
}
*/

// 포인터 훑기
// 포인터는 값이 아닌 주소를 저장하는 변수다.
// 주소를 반환하는 연산자 : &
// 포인터 변수를 선언하고 사용하는 연산자 : * (간접참조연산자)

/* 
int main() {
	int a;
	int * pa;
	a = 10;
	pa = &a;
	
	cout << "a is " << a << endl;
	cout << "a's address is " << &a << endl;
	cout << "pa is " << pa << endl;
	cout << "*pa is " << *pa << endl;
}
*/

// 함수에 매개변수를 보내서 변수 스왑하기 예제 (포인터 활용)

// 이렇게 하면 안 변함 
/*
void swap(int x, int y) { 
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}
*/

// 이렇게 하면 변함
/*
void swap(int* x, int* y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int main() {
	int a = 10;
	int b = 100;
	cout << "a : " << a << ", b : " << b << endl;
	cout << "swap a and b" << endl;
	swap(&a, &b);
	cout << "a : " << a << ", b : " << b << endl;
}
*/

//래퍼런스(reference) 예제
int main() {
	int a = 10;
	int& ra = a;

	cout << "a is " << a << endl;
	cout << "ra is " << ra << endl;

	ra = 100;
	cout << "a is " << a << endl;
	cout << "ra is " << ra << endl;
}