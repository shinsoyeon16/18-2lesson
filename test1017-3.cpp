// 학생 데이타(학번, 이름, 학과) 3개를 삽입후 출력하고, 맨 먼저 들어온 데이타를 삭제후 출력//연결리스트로 표현하는 큐
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct node { //연결 리스트를 사용하기 위한 노드 정의
	int num = NULL;
	char name[20]="";
	char dep[20]="";
	node * link = NULL;
};
struct list { //연결 리스트로 큐 연산을 하기위한 노드의 묶음 정의
	node * n = NULL;
	node * front = NULL;
	node * rear = NULL;
};

void enqueue(list * li, node * a) { //큐 삽입연산을 위한 enqueque 함수
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

node dequeue(list* li) { //큐 삭제연산을 위한 dequeque 함수
	node a;
	if (li->front == NULL) {
		cout << "저장된 데이터가 없습니다." << endl;
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

void display(list * li) { //연결리스트에 저장된 데이터를 출력하는 함수
	node * cur = li->front;
	int i = 1;
	while (1) {
		cout << "  학번              이름             학과" << endl;
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
		cout << "학번 : ";
		cin >> a.num;
		cout << "이름 : ";
		cin >> a.name;
		cout << "학과 : "; 
		cin >> a.dep;
		enqueue(list, &a);
	}
	display(list);
}