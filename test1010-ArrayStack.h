#pragma once
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>

#define MAX_STACK_SIZE 100

inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
};

class ArrayStack
{
	int  data[MAX_STACK_SIZE]; // 요소의 배열
	int  top;     // 요소의 개수

public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}
	bool isEmpty() { return top == -1; }

	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(int e) {
		if (isFull()) error("스택 포화 에러");
		data[++top] = e;
	}

	int pop() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}

	void peek() {
		if (isEmpty()) error("스택 공백 에러");
		printf("[스택 항목의 수 = %2d] ==> <%2d>\n", top + 1, data[top]);
	}

	void display() {
		printf("[스택 항목의 수 = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}

};