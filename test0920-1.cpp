#include <iostream>
#include "stdafx.h"	
using namespace std;

// 1. Circle 클래스에 매개변수를 받는 생성자를 만들지 않았습니다.
// 따라서 디폴트생성자만 있기 때문에 main 함수에서 객체생성시 
// Circle coin(3); 이 아니라 Circle coin(); 으로 생성해야 합니다.

class Circle {

public:

	int radius;

	double getArea();
};

int main() {

	Circle coin();

}



// 2. a의 생성자 실행 -> b의 생성자 실행 -> (f함수 호출) c의 생성자 실행 -> c의 소멸자 실행 (f함수 종료) -> d의 생성자 실행 -> d의 소멸자 실행 -> b의 소멸자 실행 -> a의 소멸자 실행

MyClass a, b;

Void f() {

	MyClass c;

}

int main() {

	f();

	MyClass d;

}