// �л�3�� �����Է� �ý��� �����
/*
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
			if (totalStudent == 3) {
				cout << "��� �л��� ������ �Է¿Ϸ� �Ǿ����ϴ�!!" << endl;
				break;
			}

			cout << "���� �Է�" << endl;
			int kor, eng, math, no;

			cout << "�й��� �Է��ϼ��� : ";
			cin >> no;

			cout << "����, ����, ���� ������ �Է��ϼ��� : ";
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
			//�Ҽ����� 2�ڸ����� ǥ���ǵ��� ����
			cout.precision(2);
			cout << fixed; //cout.setf(ios::fixed); �� ǥ�� ����

			cout << "���� ��ȸ" << endl;
			if (totalStudent == 0) {
				cout << "�Էµ� ������ �����ϴ�." << endl;
				break;
			}
			cout << "�й�       ����  ����  ����  ���" << endl;

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
						
			cout << "��ü ���� ��� : " << totalAvg << endl;
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
*/

// �Լ� ���� ����
#include "stdafx.h"
#include <iostream>

using namespace std;

void buy(int x, int y) { //���ϰ� ���� �Լ�
	cout << x << "����," << y << "���� ���� �����߽��ϴ�." << endl;
}
int buy2(int x, int y) { //���ϰ� �ִ� �Լ�
	int z;
	cout << x << "����," << y << "���� ���� �����߽��ϴ�." << endl;
	z = x + y;
	return z;
}
int main() {
	int inum, inum2, sum;
	cout << "���� ���ݾ�? " << endl;
	cin >> inum;
	cout << "���� ���ݾ�? " << endl;
	cin >> inum2;
	buy(inum, inum2);
	sum = buy2(inum, inum2);

	cout << "���� �հ� : " << sum << endl;

}