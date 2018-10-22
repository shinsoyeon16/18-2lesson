#include "test1011-3.h"
#include<iostream>
#include<string>
#include<fstream>
#include<stack>
using namespace std;

int main(void)
{
	//1. 중위식이 입력되어있는 파일을 불러옵니다.
	ifstream file("text.txt");
	if (file.fail()) error("Error: 파일 존재하지 않습니다.\n");

	for (int i = 0; i < 3; i++) {

		//2. 파일에서 식을 입력받아 char형 배열에 저장합니다.
		string s; 
		getline(file, s);
		int len = s.size();
		char * expcpy = new char[len];
		strcpy(expcpy, s.c_str());

		//3. 계산 프로그램인 LoadCal 함수를 호출합니다.
		cout << "중위식 : " << s << endl;
		cout<<"결과값 : " << LoadCal(expcpy) << endl<<endl;
	}

	return 0;
}

// 전체 계산 과정을 처리하는 함수
int LoadCal(char expcpy[])
{
	int len = strlen(expcpy);

	//4.중위식을 후위식으로 변환하는 Change 함수를 호출합니다.
	Change(expcpy);  

	//5. 변환된 후위식을 계산하는 함수 RunCal 함수를 호출합니다.
	cout << "후위식 : "<<expcpy << endl;
	return RunCal(expcpy);
}

// 후위식을 계산하는 함수
int RunCal(char s[]) 
{

	//계산 값을 저장하기 위한 스택 생성
	stack<int> stack;
	int len = strlen(s);

	//계산 과정에서 문자를 담을 c 변수 생성
	//	연산시 필요한 피연산자를 담을 num1, num2 변수 생성
	char c;
	int num1, num2;
	int i;

	for (i = 0; i < len; i++)
	{
		c = s[i];
		
		//c가 숫자인지 연산자인지 판단하는 조건문
			if (isdigit(c))
			{ //c가 숫자라면 스택에 바로 저장합니다.
				stack.push(c-48);
			}
			else
			{
				num2 = stack.top(); stack.pop();
				num1 = stack.top(); stack.pop();

				switch (c)
				{
				case '+':
					stack.push(num1 + num2);
					break;
				case '-':
					stack.push(num1 - num2);
					break;
				case '*':
					stack.push(num1 * num2); 
					break;
				case '/':
					stack.push(num1 / num2); 
					break;
				}
			}
	}
	return stack.top();
}
