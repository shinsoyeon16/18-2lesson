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
	cout << "������ ���� : " << rear->data << endl;
	cout << "�ּ� : " << rear << endl;

	//2��° ������ ����
	n = new node;
	n->data = 20;
	rear->link = n;
	rear = rear->link;
	cout << "������ ���� : " << rear->data << endl;
	cout << "�ּ� : " << rear << endl;

	//3��° ������ ����
	n = new node;
	n->data = 30;
	rear->link = n;
	rear = rear->link;
	cout << "������ ���� : " << rear->data << endl;
	cout << "�ּ� : " << rear << endl;

	//4��° ������ ����
	n = new node;
	n->data = 40;
	rear->link = n;
	rear = rear->link;
	rear->link = nullptr;
	cout << "������ ���� : " << rear->data << endl;
	cout << "�ּ� : " << rear << endl;

	// ������ ���� 1
	cout << "������ ���� �� ��ȯ : " << front->data << endl;
	cout << "�ּ� : " << front << endl;
	front = front->link;

	// ������ ���� 2
	cout << "������ ���� �� ��ȯ : " << front->data << endl;
	cout << "�ּ� : " << front << endl;
	front = front->link;

}