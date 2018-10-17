//연결리스트로 표현하는 큐
#include <iostream>
using namespace std;
typedef int DATA;

struct node { //연결 리스트를 사용하기 위한 노드 정의
	DATA data = NULL;
	node * link = NULL;
};
struct list { //연결 리스트로 큐 연산을 하기위한 노드의 묶음 정의
	node * n = NULL;
	node * front = NULL;
	node * rear = NULL;
};

void enqueue(list * li, DATA data){ //큐 삽입연산을 위한 enqueque 함수
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

DATA dequeue(list* li) { //큐 삭제연산을 위한 dequeque 함수
	DATA d;
	if (li->front == NULL) {
		cout << "저장된 데이터가 없습니다." << endl;
		exit(-1);
	}
	else {
		d = li->front->data;
		li->front = li->front->link;
		return d;
	}
}

void display(list * li) { //연결리스트에 저장된 데이터를 출력하는 함수
	node * cur = li->front;
	int i = 1;
	while (1) {
		cout << i << " 번째 데이터 : " << cur->data << endl;
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