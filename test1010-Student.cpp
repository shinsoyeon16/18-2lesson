#include "stdafx.h"
#include<iostream>
#include "test1010-StudentStack.h"

void main() {
	StudentStack stack;
	stack.push(Student(2015130007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	stack.peek();
	stack.push(Student(2015130100, "�̼���", "�����а�"));
	stack.peek();
	stack.push(Student(2015130135, "Ȳ��", "���а�"));
	stack.peek();

	stack.display();
	stack.pop();
	stack.display();
}
