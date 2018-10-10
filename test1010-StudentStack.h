#pragma once
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#define MAX_STRING 30
#define MAX_STACK_SIZE 100


inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
};

class Student {
	int id; // 학번
	char name[MAX_STRING]; // 이름
	char dept[MAX_STRING]; // 소속 학과
public:
	Student(int i = 0, const char* n = "", const char* d = "") { set(i, n, d); }
	void set(int i, const char* n, const char* d) {
		id = i;
		strcpy_s(name, n); // 문자열 복사 함수
		strcpy_s(dept, d); // 문자열 복사 함수
	}
	void display() {
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};

class StudentStack
{
	int top; // 요소의 개수
	Student data[MAX_STACK_SIZE];
public:
	StudentStack() { top = -1; }
	~StudentStack() {}
	bool isEmpty() { return top == -1; }

	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(Student e) {
		if (isFull()) error("스택 포화 에러");
		data[++top] = e;
	}
	Student pop() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}
	void peek() {
		if (isEmpty()) error("스택 공백 에러");
		printf("[스택 항목의 수 = %2d] ==>", top + 1);
		data[top].display();
	}
	void display() {
		printf("[전체 학생의 수 = %2d]\n", top + 1);
		for (int i = 0; i <= top; i++) {
			data[i].display();
		}
		printf("\n");
	}
};
