#include "stdafx.h"
#include <iostream>
#pragma warning(disable: 4996) //strcpy �Լ� ����
using namespace std;

class CRobot {
private:
	char name[10];
	int height;
	int weight;
	int power;

public:
	void Set(const char * n, int h, int w, int p);
	void Print();
};
void CRobot::Set(const char * n, int h, int w, int p) {
	strcpy(name, n);
	height = h;
	weight = w;
	power = p;
}

void CRobot:: Print() {
	cout << "�κ��̸� : " << name << endl;
	cout << "���� : " << height << endl;
	cout << "���� : " << weight << endl;
	cout << "���� : " << power << endl;
	cout << endl;
}

int main(void) {
	CRobot robot[3];
	char n[10];
	int h, w, p;
	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << " ��° �κ��� �̸��� �Է��ϼ��� : ";
		std::cin >> n;
		std::cout << "������ �Է��ϼ��� : ";
		std::cin >> h;
		std::cout << "������ �Է��ϼ��� : ";
		std::cin >> w;
		std::cout << "������ �Է��ϼ��� : ";
		std::cin >> p;

		robot[i].Set(n, h, w, p);
	}
	for (int i = 0; i < 3; i++) {
		robot[i].Print();
	}
	return 0;
}