#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define MAX_STACK_SIZE 100
#define Data char

int LoadCal(char expcpy[]); // 전체 계산 과정을 처리하는 함수
void Change(char expcpy[]); // 중위식을 후위식으로 변환하는 함수
int RunCal(char s[]); // 후위식을 계산하는 함수

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
		if (isFull()) error("스택 포화 에러");
		data[++top] = c;
	}
	Data pop(Stack * s) {
		if (isEmpty()) error("스택 공백 에러");
		return s->data[top--];
	}
	Data peek(Stack * s) {
		if (isEmpty()) error("스택 공백 에러");
		return s->data[top];
	}
};