/*#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nAge;

	cout << "���� �Է�." << endl;
	cin >> nAge;
	char szJob[32]; //16����
	cout << "�����Է�." << endl;
	cin >> szJob;
	std::string strName;
	std::cout << "�̸� �Է�." << endl;
	std::cin >> strName;
	std::cout << "����� �̸��� " << strName << "�̰�, "
		<< "���̴� " << nAge << "���̸�, "
		<< "������ " << szJob << "�Դϴ�. " << std::endl;

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

/* �迭 ����
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

// �ڵ��� ȸ�� ���� 1
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

//�ڵ��� ȸ�� ����2
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

//���� ���� �ع����� �����
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//����
	int s1_no, s2_no, s3_no;
	int s1_kor, s2_kor, s3_kor;
	int s1_eng, s2_eng, s3_eng;
	int s1_math, s2_math, s3_math;
	float s1_avg, s2_avg, s3_avg;
	float totalAvg = 0.0f;
	int totalStudent = 0;

	while (1) {
		//�޴�
		cout << "\n===== �������� �ý��� =====\n";
		cout << "1. ���� �߰�" << endl;
		cout << "2. ��ü ���� ����" << endl;
		cout << "3. ����" << endl;
		cout << "===========================\n";
		cout << "select >> ";

		char select;
		cin >> select;

		//�޴� ó�� ���ǹ�
		switch (select) {
		case '1':
		{
			cout << "���� �Է�" << endl;
			int kor, eng, math;
			cout << "����, ����, ���� ������ �Է��ϼ��� : ";
			cin >> kor >> eng >> math;
			float avg = (kor + eng + math) / 3.0f;
			break;
		}
		case '2':
		{
			cout << "���� ��ȸ" << endl;
			cout << "�й�     ���� ���� ���� ���" << endl;
			break;
		}
		case '3': 
			cout << endl << "�����ϰڽ��ϴ�." << endl;
			return 0;
		default: 
			cout << "���� ����" << endl;
			break;
		}
	}
}