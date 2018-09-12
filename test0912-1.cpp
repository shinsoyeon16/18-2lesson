#include "stdafx.h"
#include <iostream>
using namespace std;

// 1. 점수를 입력 받은 후 등급을 출력하는 프로그램을 switch문만 사용하여 작성

int main() {
	int score(0);
	char grade;
	//채점
	cout << "채점한 점수는 : ";
	cin >> score;
	//조건문
	switch (score / 10) {
	case 10: {grade = 'A'; break; }

	case 9: case 8: {grade = 'B'; break; }

	case 7: case 6: case 5: {grade = 'C'; break; }

	case 4: case 3: case 2: case 1: {grade = 'D'; break; }

	case 0: {grade = 'F'; break; }

	default:
		cout << "입력 오류" << endl;
		break;

	}
	cout << "학점 : " << grade << endl;
}
