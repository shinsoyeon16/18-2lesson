#include "stdafx.h"
#include <iostream>
using namespace std;

// 1. ������ �Է� ���� �� ����� ����ϴ� ���α׷��� switch���� ����Ͽ� �ۼ�

int main() {
	int score(0);
	char grade;
	//ä��
	cout << "ä���� ������ : ";
	cin >> score;
	//���ǹ�
	switch (score / 10) {
	case 10: {grade = 'A'; break; }

	case 9: case 8: {grade = 'B'; break; }

	case 7: case 6: case 5: {grade = 'C'; break; }

	case 4: case 3: case 2: case 1: {grade = 'D'; break; }

	case 0: {grade = 'F'; break; }

	default:
		cout << "�Է� ����" << endl;
		break;

	}
	cout << "���� : " << grade << endl;
}
