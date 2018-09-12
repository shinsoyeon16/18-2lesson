/*#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nAge;

	cout << "나이 입력." << endl;
	cin >> nAge;
	char szJob[32]; //16글자
	cout << "직업입력." << endl;
	cin >> szJob;
	std::string strName;
	std::cout << "이릅 입력." << endl;
	std::cin >> strName;
	std::cout << "당신의 이름은 " << strName << "이고, "
		<< "나이는 " << nAge << "살이며, "
		<< "직업은 " << szJob << "입니다. " << std::endl;

	return 0;
}*/

/*
void TestFunc(int, char*) {

}
int main(void) {
	auto pfTest(TestFunc);
	void(*pfTest) (int, char*) = TestFunc;
	return 0;
}*/

/* 배열 예제
int _tmain(int argc, _TCHAR* argv[])
{
	int aList[5] = { 10,20,30 };
	for (auto n : aList)
		cout << n << ' ';
	cout << endl;

	for (auto &n : aList)
		cout << n << ' ';
	cout << endl;
	return 0;
}*/

// 자동차 회사 예제 1
/* int x;
void setx() {
	x = 100;
}
namespace kia {
	int x;
	void setx() {
		x = 200;
	}
}
namespace samsung {
	int x;
	void setx() {
		x = 300;
	}
}
namespace hyundai {
	int x;
	void setx() {
		x = 500;
	}
}
int main() {
	::setx();
	kia::setx();
	samsung::setx();
	hyundai::setx();
	cout << x << endl;
	cout << kia::x << endl;
	cout << samsung::x << endl;
	cout << hyundai::x << endl;
} 
*/

//자동차 회사 예제2
/* int a;
void setValue() {
	a = 10;
}
namespace kia {
	int a;
	void setValue() {
		a = 100;
	}
	namespace daewoo {
		//int a;
		void setValue() {
			a = 1000;
		}
		int a;
	}
}
namespace kd = kia::daewoo;

int main() {
	using namespace kia;
	::setValue();
	kia::setValue();
	daewoo::setValue();
	cout << ::a << endl;
	cout << kia::a<< endl;
	cout << kd::a << endl;
}
*/

//내일 과제 밑바탕만 만들기
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
			cout << "성적 입력" << endl;
			int kor, eng, math;
			cout << "국어, 영어, 수학 점수를 입력하세요 : ";
			cin >> kor >> eng >> math;
			float avg = (kor + eng + math) / 3.0f;
			break;
		}
		case '2':
		{
			cout << "성적 조회" << endl;
			cout << "학번     국어 영어 수학 평균" << endl;
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