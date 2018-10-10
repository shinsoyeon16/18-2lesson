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
	int id; // �й�
	char name[MAX_STRING]; // �̸�
	char dept[MAX_STRING]; // �Ҽ� �а�
public:
	Student(int i = 0, const char* n = "", const char* d = "") { set(i, n, d); }
	void set(int i, const char* n, const char* d) {
		id = i;
		strcpy_s(name, n); // ���ڿ� ���� �Լ�
		strcpy_s(dept, d); // ���ڿ� ���� �Լ�
	}
	void display() {
		printf(" �й�:%-15d ����:%-10s �а�:%-20s\n", id, name, dept);
	}
};

class StudentStack
{
	int top; // ����� ����
	Student data[MAX_STACK_SIZE];
public:
	StudentStack() { top = -1; }
	~StudentStack() {}
	bool isEmpty() { return top == -1; }

	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(Student e) {
		if (isFull()) error("���� ��ȭ ����");
		data[++top] = e;
	}
	Student pop() {
		if (isEmpty()) error("���� ���� ����");
		return data[top--];
	}
	void peek() {
		if (isEmpty()) error("���� ���� ����");
		printf("[���� �׸��� �� = %2d] ==>", top + 1);
		data[top].display();
	}
	void display() {
		printf("[��ü �л��� �� = %2d]\n", top + 1);
		for (int i = 0; i <= top; i++) {
			data[i].display();
		}
		printf("\n");
	}
};
