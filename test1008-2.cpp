#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

int main(void) {
	//������ �迭 ����
	int arr[5][4];

	// 100 ������ ����� �������� ����
	srand((unsigned int)time(NULL));
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			arr[j][i] = (rand() %101);
		}
	}

	//�迭 �� Ȯ��
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			cout << arr[j][i] << " ";
		}
		cout<<endl;
	}

	//max ������ ���Ͽ� �� ū ���� ����
	int max = arr[0][0];
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			if (arr[j][i] >= max) max = arr[j][i];
		}
	}
	cout << "max : " << max << endl;
	return 0;
}