// 이진트리 클래스
#include "test1022-TreeNode.h"
#include <stdlib.h>

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

class Queue {
	int front;
	int rear;
	Node * data[100];
public:
	Queue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return ((rear + 1) % 100) == front; }
	void enqueue(Node* n) {
		if (isFull()) error("Error : 큐 포화상태\n");
		else {
			rear = (rear + 1) % 100;
			data[rear] = n;
		}
	}
	Node * dequeue() {
		if (isEmpty()) error("Error : 큐 공백상태\n");
		else {
			front = (front + 1) % 100;
			return data[front];
		}
	}
};

class Tree {
	Node* root;
public:
	Tree() : root(NULL) {}
	void setRoot(Node* node) {	root = node;	}
	Node* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }
	
	// 트리 순회 함수들
	void inorder() { printf("\n     inorder: "); inorder(root); } // 중위식 순회
	void inorder(Node* node) { //중위식 순회 오버로딩
		if (node != NULL) {
			if (node->getLeft() != NULL) inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}
	void preorder() { printf("\n     preorder: "); preorder(root); } //전위식 순회
	void preorder(Node* node) { //전위식 순회 오버로딩
		if (node != NULL) {
			printf(" [%c] ", node->getData());
			if (node->getLeft() != NULL) preorder(node->getLeft());
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}
	void postorder() { printf("\n     postorder: "); postorder(root); } //후위식 순회
	void postorder(Node* node) { //후위식 순회 오버로딩
		if (node != NULL) {
			if (node->getLeft() != NULL) postorder(node->getLeft());
			if (node->getRight() != NULL) postorder(node->getRight());
			printf(" [%c] ", node->getData());
		}
	}
	void levelorder() { //레벨 순회
		printf("\n     levelorder: ");
		if (!isEmpty()) {
			Queue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				Node* n = q.dequeue();
				if (n != NULL) {
					printf(" [%c] ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}

	// 트리 연산 함수들
	int getCount() { return isEmpty() ? 0 : getCount(root); } //전체 노드 수 구하기
	int getCount(Node *node) { //오버로딩
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft())
			+ getCount(node->getRight());
	}

	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); } //자식 노드 수 구하기
	int getLeafCount(Node* node) {  //오버로딩
		if (node == NULL) return 0;
		if (node->getLeft() == NULL && node->getRight() == NULL) {
			return 1;
		}
		else
			return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	int getHeight() { return isEmpty() ? 0 : getHeight(root); } //트리의 높이 구하기
	int getHeight(Node *node) { //오버로딩
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
	}
};