#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

int main(void) {
	//이차원 배열 선언
	int arr[5][4];

	// 100 이하의 양수를 랜덤으로 저장
	srand((unsigned int)time(NULL));
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			arr[j][i] = (rand() %101);
		}
	}

	//배열 값 확인
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			cout << arr[j][i] << " ";
		}
		cout<<endl;
	}

	//max 변수와 비교하여 더 큰 값을 저장
	int max = arr[0][0];
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			if (arr[j][i] >= max) max = arr[j][i];
		}
	}
	cout << "max : " << max << endl;
	return 0;
}