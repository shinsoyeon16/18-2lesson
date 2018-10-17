//���Ḯ��Ʈ�� ǥ���ϴ� ť
#include <iostream>
using namespace std;
typedef int DATA;

struct node { //���� ����Ʈ�� ����ϱ� ���� ��� ����
	DATA data = NULL;
	node * link = NULL;
};
struct list { //���� ����Ʈ�� ť ������ �ϱ����� ����� ���� ����
	node * n = NULL;
	node * front = NULL;
	node * rear = NULL;
};

void enqueue(list * li, DATA data){ //ť ���Կ����� ���� enqueque �Լ�
	if (li->front == NULL) {
		li->n = new node;
		li->n->data = data;
		li->front = li->n;
		li->rear = li->n;
	}
	else {
		li->n = new node;
		li->n->data = data;
		li->rear->link = li->n;
		li->rear = li->n;
		li->rear->link = NULL;
	}
}

DATA dequeue(list* li) { //ť ���������� ���� dequeque �Լ�
	DATA d;
	if (li->front == NULL) {
		cout << "����� �����Ͱ� �����ϴ�." << endl;
		exit(-1);
	}
	else {
		d = li->front->data;
		li->front = li->front->link;
		return d;
	}
}

void display(list * li) { //���Ḯ��Ʈ�� ����� �����͸� ����ϴ� �Լ�
	node * cur = li->front;
	int i = 1;
	while (1) {
		cout << i << " ��° ������ : " << cur->data << endl;
		if (cur->link == NULL) break;
		cur = cur->link;
		i++;
	}
}

void main() {
	struct list li;
	list * list = &li;
	DATA a = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a;
	enqueue(list, a);
}
	dequeue(list); dequeue(list);
	display(list);
}