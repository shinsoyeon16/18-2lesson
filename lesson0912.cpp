// 학생3명 성적입력 시스템 만들기
/*
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//변수
	int s1_no, s2_no, s3_no;
	int s1_kor, s2_kor, s3_kor;
	int s1_eng, s2_eng, s3_eng;
	int s1_math, s2_math, s3_math;
	float s1_avg, s2_avg, s3_avg;
	float totalAvg = 0.0f;
	int totalStudent = 0;

	while (1) {
		//메뉴
		cout << "\n===== 성적관리 시스템 =====\n";
		cout << "1. 성적 추가" << endl;
		cout << "2. 전체 성적 보기" << endl;
		cout << "3. 종료" << endl;
		cout << "===========================\n";
		cout << "select >> ";

		char select;
		cin >> select;

		//메뉴 처리 조건문
		switch (select) {
		case '1':
		{
			if (totalStudent == 3) {
				cout << "모든 학생의 성적이 입력완료 되었습니다!!" << endl;
				break;
			}

			cout << "성적 입력" << endl;
			int kor, eng, math, no;

			cout << "학번을 입력하세요 : ";
			cin >> no;

			cout << "국어, 영어, 수학 점수를 입력하세요 : ";
			cin >> kor >> eng >> math;
			float avg = (kor + eng + math) / 3.0f;
			if (totalStudent == 0) {
				s1_kor = kor;
				s1_eng = eng;
				s1_math = math;
				s1_avg = avg;
				s1_no = no;
				totalAvg = s1_avg;
			} else if (totalStudent == 1) {
				s2_kor = kor;
				s2_eng = eng;
				s2_math = math;
				s2_avg = avg;
				s2_no = no;
				totalAvg = (s1_avg + s2_avg) / 2;
			} else if (totalStudent == 2) {
				s3_kor = kor;
				s3_eng = eng;
				s3_math = math;
				s3_avg = avg;
				s3_no = no;
				totalAvg = (s1_avg + s2_avg + s3_avg) / 3;
			}
			totalStudent++;
			break;
		}
		case '2':
		{
			//소수점을 2자리까지 표현되도록 고정
			cout.precision(2);
			cout << fixed; //cout.setf(ios::fixed); 로 표현 가능

			cout << "성적 조회" << endl;
			if (totalStudent == 0) {
				cout << "입력된 정보가 없습니다." << endl;
				break;
			}
			cout << "학번       국어  영어  수학  평균" << endl;

			for (int i = 0; i < totalStudent; ++i) {
				if (i == 0) {
					cout << setw(7) << s1_no << " " << setw(5) << s1_kor << " " << setw(5) << s1_eng << " ";
					cout << setw(5) << s1_math << " " << setw(7) << s1_avg << endl;
				} else if (i == 1) {
					cout << setw(7) << s2_no << " " << setw(5) << s2_kor << " " << setw(5) << s2_eng << " ";
					cout << setw(5) << s2_math << " " << setw(7) << s2_avg << endl;
				} else {
					cout << setw(7) << s3_no << " " << setw(5) << s3_kor << " " << setw(5) << s3_eng << " ";
					cout << setw(5) << s3_math << " " << setw(7) << s3_avg << endl;
				}
			}
						
			cout << "전체 성적 평균 : " << totalAvg << endl;
			break;
		}
		case '3':
			cout << endl << "종료하겠습니다." << endl;
			return 0;
		default:
			cout << "선택 오류" << endl;
			break;
		}
	}
}
*/

// 함수 설명 예제
#include "stdafx.h"
#include <iostream>

using namespace std;

void buy(int x, int y) { //리턴값 없는 함수
	cout << x << "만원," << y << "만원 차를 구입했습니다." << endl;
}
int buy2(int x, int y) { //리턴값 있는 함수
	int z;
	cout << x << "만원," << y << "만원 차를 구입했습니다." << endl;
	z = x + y;
	return z;
}
int main() {
	int inum, inum2, sum;
	cout << "차량 가격얼마? " << endl;
	cin >> inum;
	cout << "차량 가격얼마? " << endl;
	cin >> inum2;
	buy(inum, inum2);
	sum = buy2(inum, inum2);

	cout << "차량 합계 : " << sum << endl;

}