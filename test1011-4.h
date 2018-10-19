#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stack>
using namespace std;

inline void error(const char * msg) {
	printf("%s\n", msg);
	exit(1);
}

bool CheckMatching(const char* filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) error("Error: ���� �������� �ʽ��ϴ�.\n");

	int nLine = 1, nChar = 0;
	stack<char> stack;
	char ch;

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') nLine++;
		nChar++;
		if (ch == '[' || ch == '(' || ch == '{')
			stack.push(ch);
		else if (ch == ']' || ch == ')' || ch == '}') {
			int prev = stack.top();
			stack.pop();
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) break;
		}
	}
	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename);
	if (!stack.empty())
		printf("Error! (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	else
		printf("  OK: (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	return stack.empty();
}