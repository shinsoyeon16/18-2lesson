#include "test1011-3.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>
using namespace std;

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

int WhoHighPosition(char ex1, char ex2)
{
	int ex1Position = Position(ex1);
	int ex2Position = Position(ex2);

	if (ex1Position > ex2Position)
		return 1;
	else if (ex1Position < ex2Position)
		return -1;
	else
		printf("문제발견\n");
		return 0;
}

void Change(char s[])
{
	printf("체인지 실행");
	Stack stack;
	int len = strlen(s);
	char * convExp = new char[len];

	int i, idx = 0;
	char ex, pop;

	for (i = 0; i<len; i++)
	{
		printf("반복문실행");
		ex = s[i];
		if (isdigit(ex))
		{
			convExp[idx++] = ex;
		}
		else
		{
			switch (ex)
			{
				printf("스위치실행");
				cout<<convExp[idx]<< endl;
			case '(':
				stack.push(ex);
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
				printf("케이스 실행");
				while (!stack.isEmpty() &&
					WhoHighPosition(ex,stack.peek(&stack)))
					convExp[idx++] = stack.pop(&stack);
				stack.push(ex);
				break;
			}
		}
	}
	printf("와일 탈출");
	while (!stack.isEmpty())
		convExp[idx++] = stack.pop(&stack);

	strcpy(s, convExp);
	delete  []convExp;
}