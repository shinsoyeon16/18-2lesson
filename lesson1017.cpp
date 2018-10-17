//연결리스트로 표현하는 큐
#include <iostream>
using namespace std;

struct node {
	int data;
	node * link;
};

void main() {
	node * n;
	node * front;
	node * rear;

	//1번째 데이터 저장
	n = new node;
	n->data = 10;
	front = n;
	rear = n;
	cout << "데이터 저장 : " << rear->data << endl;
	cout << "주소 : " << rear << endl;

	//2번째 데이터 저장
	n = new node;
	n->data = 20;
	rear->link = n;
	rear = rear->link;
	cout << "데이터 저장 : " << rear->data << endl;
	cout << "주소 : " << rear << endl;

	//3번째 데이터 저장
	n = new node;
	n->data = 30;
	rear->link = n;
	rear = rear->link;
	cout << "데이터 저장 : " << rear->data << endl;
	cout << "주소 : " << rear << endl;

	//4번째 데이터 저장
	n = new node;
	n->data = 40;
	rear->link = n;
	rear = rear->link;
	rear->link = nullptr;
	cout << "데이터 저장 : " << rear->data << endl;
	cout << "주소 : " << rear << endl;

	// 데이터 삭제 1
	cout << "데이터 삭제 및 반환 : " << front->data << endl;
	cout << "주소 : " << front << endl;
	front = front->link;

	// 데이터 삭제 2
	cout << "데이터 삭제 및 반환 : " << front->data << endl;
	cout << "주소 : " << front << endl;
	front = front->link;

}