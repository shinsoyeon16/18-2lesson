#include "test1011-3.h"
#include<iostream>
#include<string>
#include<fstream>
#include<stack>
using namespace std;

int main(void)
{
	//1. �������� �ԷµǾ��ִ� ������ �ҷ��ɴϴ�.
	ifstream file("text.txt");
	if (file.fail()) error("Error: ���� �������� �ʽ��ϴ�.\n");

	for (int i = 0; i < 3; i++) {

		//2. ���Ͽ��� ���� �Է¹޾� char�� �迭�� �����մϴ�.
		string s; 
		getline(file, s);
		int len = s.size();
		char * expcpy = new char[len];
		strcpy(expcpy, s.c_str());

		//3. ��� ���α׷��� LoadCal �Լ��� ȣ���մϴ�.
		cout << "������ : " << s << endl;
		cout<<"����� : " << LoadCal(expcpy) << endl<<endl;
	}

	return 0;
}

// ��ü ��� ������ ó���ϴ� �Լ�
int LoadCal(char expcpy[])
{
	int len = strlen(expcpy);

	//4.�������� ���������� ��ȯ�ϴ� Change �Լ��� ȣ���մϴ�.
	Change(expcpy);  

	//5. ��ȯ�� �������� ����ϴ� �Լ� RunCal �Լ��� ȣ���մϴ�.
	cout << "������ : "<<expcpy << endl;
	return RunCal(expcpy);
}

// �������� ����ϴ� �Լ�
int RunCal(char s[]) 
{

	//��� ���� �����ϱ� ���� ���� ����
	stack<int> stack;
	int len = strlen(s);

	//��� �������� ���ڸ� ���� c ���� ����
	//	����� �ʿ��� �ǿ����ڸ� ���� num1, num2 ���� ����
	char c;
	int num1, num2;
	int i;

	for (i = 0; i < len; i++)
	{
		c = s[i];
		
		//c�� �������� ���������� �Ǵ��ϴ� ���ǹ�
			if (isdigit(c))
			{ //c�� ���ڶ�� ���ÿ� �ٷ� �����մϴ�.
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
