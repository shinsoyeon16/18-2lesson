#pragma once
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>

#define MAX_STACK_SIZE 100
#define DATA char

inline void error(const char * msg) {
	printf("%s\n", msg);
	exit(1);
}
class ArrayStack
{
	int top;
	DATA data[MAX_STACK_SIZE];
public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == MAX_STACK_SIZE - 1;	
	}

	void push(DATA e) {
		if (isFull()) error("���� ��ȭ ����");
		data[++top]=e;
	}
	DATA pop() {
		if (isEmpty()) error("���� ���� ����");
		return data[top--];
	}
	DATA peek() {
		if (isEmpty()) error("���� ���� ����");
		return data[top];
	}
	void display() {
		printf("[���� �׸��� �� = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%2c>", data[i]);
		printf("\n");
	}
};