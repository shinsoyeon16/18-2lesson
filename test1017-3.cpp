// �л� ����Ÿ(�й�, �̸�, �а�) 3���� ������ ����ϰ�, �� ���� ���� ����Ÿ�� ������ ���//���Ḯ��Ʈ�� ǥ���ϴ� ť
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct node { //���� ����Ʈ�� ����ϱ� ���� ��� ����
	int num = NULL;
	char name[20]="";
	char dep[20]="";
	node * link = NULL;
};
struct list { //���� ����Ʈ�� ť ������ �ϱ����� ����� ���� ����
	node * n = NULL;
	node * front = NULL;
	node * rear = NULL;
};

void enqueue(list * li, node * a) { //ť ���Կ����� ���� enqueque �Լ�
	if (li->front == NULL) {
		li->n = new node;
		li->n->num = a->num;
		strcpy(li->n->name, a->name);
		strcpy(li->n->dep, a->dep);
		li->front = li->n;
		li->rear = li->n;
	}
	else {
		li->n = new node;
		li->n->num = a->num;
		strcpy(li->n->name, a->name);
		strcpy(li->n->dep, a->dep);
		li->rear->link = li->n;
		li->rear = li->n;
		li->rear->link = NULL;
	}
}

node dequeue(list* li) { //ť ���������� ���� dequeque �Լ�
	node a;
	if (li->front == NULL) {
		cout << "����� �����Ͱ� �����ϴ�." << endl;
		exit(-1);
	}
	else {
		a.num = li->front->num;
		strcpy(a.name, li->n->name);
		strcpy(a.dep, li->n->dep);
		li->front = li->front->link;
		return a;
	}
}

void display(list * li) { //���Ḯ��Ʈ�� ����� �����͸� ����ϴ� �Լ�
	node * cur = li->front;
	int i = 1;
	while (1) {
		cout << "  �й�              �̸�             �а�" << endl;
		printf("%-19d%-15s%-19s\n", cur->num, cur->name, cur->dep);
		if (cur->link == NULL) break;
		cur = cur->link;
		i++;
	}
}

void main() {
	struct list li;
	list * list = &li;
	node a;
	for (int i = 0; i < 3; i++) {
		cout << "�й� : ";
		cin >> a.num;
		cout << "�̸� : ";
		cin >> a.name;
		cout << "�а� : "; 
		cin >> a.dep;
		enqueue(list, &a);
	}
	display(list);
}