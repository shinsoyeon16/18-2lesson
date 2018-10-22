// ����Ʈ�� Ŭ����
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
		if (isFull()) error("Error : ť ��ȭ����\n");
		else {
			rear = (rear + 1) % 100;
			data[rear] = n;
		}
	}
	Node * dequeue() {
		if (isEmpty()) error("Error : ť �������\n");
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
	
	// Ʈ�� ��ȸ �Լ���
	void inorder() { printf("\n     inorder: "); inorder(root); } // ������ ��ȸ
	void inorder(Node* node) { //������ ��ȸ �����ε�
		if (node != NULL) {
			if (node->getLeft() != NULL) inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}
	void preorder() { printf("\n     preorder: "); preorder(root); } //������ ��ȸ
	void preorder(Node* node) { //������ ��ȸ �����ε�
		if (node != NULL) {
			printf(" [%c] ", node->getData());
			if (node->getLeft() != NULL) preorder(node->getLeft());
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}
	void postorder() { printf("\n     postorder: "); postorder(root); } //������ ��ȸ
	void postorder(Node* node) { //������ ��ȸ �����ε�
		if (node != NULL) {
			if (node->getLeft() != NULL) postorder(node->getLeft());
			if (node->getRight() != NULL) postorder(node->getRight());
			printf(" [%c] ", node->getData());
		}
	}
	void levelorder() { //���� ��ȸ
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

	// Ʈ�� ���� �Լ���
	int getCount() { return isEmpty() ? 0 : getCount(root); } //��ü ��� �� ���ϱ�
	int getCount(Node *node) { //�����ε�
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft())
			+ getCount(node->getRight());
	}

	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); } //�ڽ� ��� �� ���ϱ�
	int getLeafCount(Node* node) {  //�����ε�
		if (node == NULL) return 0;
		if (node->getLeft() == NULL && node->getRight() == NULL) {
			return 1;
		}
		else
			return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	int getHeight() { return isEmpty() ? 0 : getHeight(root); } //Ʈ���� ���� ���ϱ�
	int getHeight(Node *node) { //�����ε�
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
	}
};