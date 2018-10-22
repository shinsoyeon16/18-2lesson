#include "test1011-3.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>
using namespace std;

// 연산자의 우선순위를 지정하는 함수
int Position(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 2;
	case '(':
		return 1;
	}

	return -1; 
}

// 연산자의 우선순위를 비교하는 함수
int WhoHighPosition(char ex1, char ex2)
{
	int ex1Position = Position(ex1);
	int ex2Position = Position(ex2);

	if (ex1Position > ex2Position)
		return 1;
	else if (ex1Position < ex2Position)
		return -1;
	else
		return 0;
}

// 중위식을 후위식으로 변환하는 함수
void Change(char expcpy[])
{
	Stack stack; //수식 변환 중 연산자 저장을 위한 스택생성
	int len = strlen(expcpy);
	char * convExp = new char[len];

	int i, idx = 0;
	//후위식으로 변환시 문자를 담을 c 변수와
	//연산자를 담을 pop변수 선언
	char c, pop; 

	for (i = 0; i<len; i++)
	{
		c = expcpy[i];
		// c에 담긴 문자가 숫자인지 연산지인지 판단하는 조건문
		if (isdigit(c))
		{
			convExp[idx++] = c; //숫자라면 바로 convExp 배열에 저장
		}
		else
		{
			switch (c)
			{
			case '(':
				stack.push(c);
				break;

			case ')':
				while (1)
				{
					pop = stack.pop(&stack);
					if (pop == '(')
						break;
					convExp[idx++] = pop;
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while (!stack.isEmpty() &&
					WhoHighPosition(stack.peek(&stack),c)>=0)
					convExp[idx++] = stack.pop(&stack);
				stack.push(c);
				break;
			}
		}
	}
	while (!stack.isEmpty()) {
		convExp[idx++] = stack.pop(&stack);
	}
	convExp[idx] = '\0';
	strcpy(expcpy, convExp);
	delete[] convExp;
}