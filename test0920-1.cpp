#include <iostream>
#include "stdafx.h"	
using namespace std;

// 1. Circle Ŭ������ �Ű������� �޴� �����ڸ� ������ �ʾҽ��ϴ�.
// ���� ����Ʈ�����ڸ� �ֱ� ������ main �Լ����� ��ü������ 
// Circle coin(3); �� �ƴ϶� Circle coin(); ���� �����ؾ� �մϴ�.

class Circle {

public:

	int radius;

	double getArea();
};

int main() {

	Circle coin();

}



// 2. a�� ������ ���� -> b�� ������ ���� -> (f�Լ� ȣ��) c�� ������ ���� -> c�� �Ҹ��� ���� (f�Լ� ����) -> d�� ������ ���� -> d�� �Ҹ��� ���� -> b�� �Ҹ��� ���� -> a�� �Ҹ��� ����

MyClass a, b;

Void f() {

	MyClass c;

}

int main() {

	f();

	MyClass d;

}