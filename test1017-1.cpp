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

	//2번째 데이터 저장
	n = new node;
	n->data = 20;
	rear->link = n;
	rear = rear->link;

	//3번째 데이터 저장
	n = new node;
	n->data = 30;
	rear->link = n;
	rear = rear->link;

	//4번째 데이터 저장
	n = new node;
	n->data = 40;
	rear->link = n;
	rear = rear->link;
	rear->link = nullptr;

	// 데이터 삭제 1
	cout << "데이터 삭제 및 반환 : " << front->data << endl;
	cout << endl;
	front = front->link;

	// 데이터 삭제 2
	cout << "데이터 삭제 및 반환 : " << front->data << endl;
	cout << endl;
	front = front->link;

	//데이터 전체 출력
	node * cur = front;
	int i = 0;
	while(1){
		i++;
		cout << i << " 번째 데이터 : " << cur->data << endl;
		if (cur->link == NULL) break;
		cur = cur->link;
	}

}