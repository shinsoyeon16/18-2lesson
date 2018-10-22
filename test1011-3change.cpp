#include "test1011-3.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>
using namespace std;

// �������� �켱������ �����ϴ� �Լ�
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

// �������� �켱������ ���ϴ� �Լ�
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

// �������� ���������� ��ȯ�ϴ� �Լ�
void Change(char expcpy[])
{
	Stack stack; //���� ��ȯ �� ������ ������ ���� ���û���
	int len = strlen(expcpy);
	char * convExp = new char[len];

	int i, idx = 0;
	//���������� ��ȯ�� ���ڸ� ���� c ������
	//�����ڸ� ���� pop���� ����
	char c, pop; 

	for (i = 0; i<len; i++)
	{
		c = expcpy[i];
		// c�� ��� ���ڰ� �������� ���������� �Ǵ��ϴ� ���ǹ�
		if (isdigit(c))
		{
			convExp[idx++] = c; //���ڶ�� �ٷ� convExp �迭�� ����
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