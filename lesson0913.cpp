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

// �޼ҵ� �����ε� ����
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
	cout << "3�� �Է�" << endl;
	cin >> a >> b >> c;
	cout << "�Ҽ� 2�� �Է�" << endl;
	cin >> da >> db;
	int res1 = max(a, b);
	int res2 = max(a, b, c);
	double res3 = max(da, db);
	
	cout << res1 << endl;
	cout << res2 << endl;
	cout << res3 << endl;
}
*/

// �Լ� ���ø� ����
/*
template <typename T1, typename T2> // �Լ� ���ø� ����
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

// ������ �ȱ�
// �����ʹ� ���� �ƴ� �ּҸ� �����ϴ� ������.
// �ּҸ� ��ȯ�ϴ� ������ : &
// ������ ������ �����ϰ� ����ϴ� ������ : * (��������������)

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

// �Լ��� �Ű������� ������ ���� �����ϱ� ���� (������ Ȱ��)

// �̷��� �ϸ� �� ���� 
/*
void swap(int x, int y) { 
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}
*/

// �̷��� �ϸ� ����
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

//���۷���(reference) ����
int main() {
	int a = 10;
	int& ra = a;

	cout << "a is " << a << endl;
	cout << "ra is " << ra << endl;

	ra = 100;
	cout << "a is " << a << endl;
	cout << "ra is " << ra << endl;
}