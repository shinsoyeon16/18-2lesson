//���Ḯ��Ʈ�� ǥ���ϴ� ť

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

	//1��° ������ ����
	n = new node;
	n->data = 10;
	front = n;
	rear = n;

	//2��° ������ ����
	n = new node;
	n->data = 20;
	rear->link = n;
	rear = rear->link;

	//3��° ������ ����
	n = new node;
	n->data = 30;
	rear->link = n;
	rear = rear->link;

	//4��° ������ ����
	n = new node;
	n->data = 40;
	rear->link = n;
	rear = rear->link;
	rear->link = nullptr;

	// ������ ���� 1
	cout << "������ ���� �� ��ȯ : " << front->data << endl;
	cout << endl;
	front = front->link;

	// ������ ���� 2
	cout << "������ ���� �� ��ȯ : " << front->data << endl;
	cout << endl;
	front = front->link;

	//������ ��ü ���
	node * cur = front;
	int i = 0;
	while(1){
		i++;
		cout << i << " ��° ������ : " << cur->data << endl;
		if (cur->link == NULL) break;
		cur = cur->link;
	}

}