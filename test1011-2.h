﻿#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

bool CheckMatching(const char* filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) error("Error: 파일 존재하지 않습니다.\n");

	int nLine = 1, nChar = 0;
	ArrayStack stack;
	char ch;

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') nLine++;
		nChar++;
		if (ch == '[' || ch == '(' || ch == '{')
			stack.push(ch);
		else if (ch == ']' || ch == ')' || ch == '}') {
			int prev = stack.pop();
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) break;
		}
	}
	fclose(fp);
	printf("[%s] 파일 검사결과:\n", filename);
	if (!stack.isEmpty())
		printf("Error! (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	else
		printf("  OK: (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}