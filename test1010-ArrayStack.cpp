// ArrStack.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.

#include "stdafx.h"
#include "test1010-ArrayStack.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>

using namespace std;

int main()
{
	ArrayStack stack;

	for (int i = 1; i<10; i++) {
		stack.push(i*2);
		stack.peek();
	}

	stack.display();

	for (int i = 1; i<10; i++) {
		stack.pop();
		stack.peek();
	}

	stack.display();
}