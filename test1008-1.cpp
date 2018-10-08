#include <iostream>
using namespace std;

class Stack
{
	//배열 선언
	int arr[100];

public:
	//메소드 선언
	void push(int num, int index)
	{
		arr[index] = num;
	}
	void showArr(int index) {
		for (int i = 0; i < index; i++) {
			cout << endl << "arr[" << i << "] = " << arr[i] << endl;
		}
	}
};


int main(void)
{
	int num = 0, i;
	Stack s;
	for (i=0;;i++)
	{
		cout << i+1 << " 번째 숫자를 입력하세요. (종료: -1)" << endl;
		cin >> num;
		if (num == -1) {
			break;
		}
		s.push(num, i);
	}	
	s.showArr(i);

	return 0;
}