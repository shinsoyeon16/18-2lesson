#include "test1011-3.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<fstream>
using namespace std;

int main(void)
{
	ifstream inFile("text.txt");
	char s[20];
	while (!inFile.eof()) {

		inFile.getline(s, 20);
		cout << s << endl;
	}

	printf("%s = %d \n", s, Cal1(s));
	delete [] s;
	return 0;
}

int Cal1(char s[])
{
	int len = strlen(s);
	int result;
	char * expcpy = new char[len];
	strcpy(expcpy, s);

	Change(expcpy);
	printf("체인지 끝\n");
	result = Cal2(expcpy);
	delete []expcpy;
	return result;
}

int Cal2(char s[]) // 후위법 수식 계산
{
	Stack stack;
	int len = strlen(s);
	int i;
	char ex, ex1, ex2;

	for (i = 0; i<len; i++)
	{
		ex = s[i];

		if (isdigit(ex))
		{
			stack.push(ex-'0');     // 숫자로 변환하여 PUSH!
		}
		else
		{
			ex2 = stack.pop(&stack);     // 먼저 꺼낸 값이 두 번째 피연산자!
			ex1 = stack.pop(&stack);

			switch (ex)
			{
			case '+':
				stack.push(ex1+ex2);
				break;
			case '-':
				stack.push(ex1 - ex2);
				break;
			case '*':
				stack.push(ex1 * ex2);
				break;
			case '/':
				stack.push(ex1 / ex2);
				break;
			}
		}
	}
	return stack.pop(&stack);
}
