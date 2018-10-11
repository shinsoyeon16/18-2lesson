#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>

#define MAX_STACK_SIZE 100
#define Data char

inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
};

class Stack
{
	Data  data[MAX_STACK_SIZE]; // 요소의 배열
	int  top;     // 요소의 개수

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
		return s->data[top];
	}

	Data peek(Stack * s) {
		if (isEmpty()) error("스택 공백 에러");
		printf("[스택 항목의 수 = %2d] ==> <%2d>\n", top + 1, data[top]);
		return s->data[top];
	}

};

int Cal1(char e[]);
int Cal2(char e[]);
void Change(char e[]);