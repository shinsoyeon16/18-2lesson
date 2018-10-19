#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define MAX_STACK_SIZE 100
#define Data char

int LoadCal(char expcpy[]); // ��ü ��� ������ ó���ϴ� �Լ�
void Change(char expcpy[]); // �������� ���������� ��ȯ�ϴ� �Լ�
int RunCal(char s[]); // �������� ����ϴ� �Լ�

inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
};

class Stack
{
	Data  data[MAX_STACK_SIZE];
	int  top;

public:
	Stack() { top = -1; }
	~Stack() {}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	void push(Data c) {
		if (isFull()) error("���� ��ȭ ����");
		data[++top] = c;
	}
	Data pop(Stack * s) {
		if (isEmpty()) error("���� ���� ����");
		return s->data[top--];
	}
	Data peek(Stack * s) {
		if (isEmpty()) error("���� ���� ����");
		return s->data[top];
	}
};