#include <iostream>
#include "stdafx.h"	
using namespace std;

class Tower {
	int height;
public:
	Tower() {
		height = 1;
	};
	Tower(int a) {
		height = a;
	}
	int getHeight() {
		return height;
	}
};

int main() {

	Tower myTower; // 1����

	Tower seoulTower(100); //100����

	cout << "���̴�" << myTower.getHeight() << "����" << endl;

	cout << "���̴�" << seoulTower.getHeight() << "����" << endl;

}



