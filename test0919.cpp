#include "stdafx.h"
#include <iostream>
#pragma warning(disable: 4996) //strcpy 함수 오류
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
	cout << "로봇이름 : " << name << endl;
	cout << "신장 : " << height << endl;
	cout << "무게 : " << weight << endl;
	cout << "마력 : " << power << endl;
	cout << endl;
}

int main(void) {
	CRobot robot[3];
	char n[10];
	int h, w, p;
	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << " 번째 로봇의 이름을 입력하세요 : ";
		std::cin >> n;
		std::cout << "신장을 입력하세요 : ";
		std::cin >> h;
		std::cout << "무게을 입력하세요 : ";
		std::cin >> w;
		std::cout << "마력을 입력하세요 : ";
		std::cin >> p;

		robot[i].Set(n, h, w, p);
	}
	for (int i = 0; i < 3; i++) {
		robot[i].Print();
	}
	return 0;
}