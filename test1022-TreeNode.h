// 이진트리를 위한 노드 클래스
#include <cstdio>
class Node
{
protected:
	int data;
	Node * left;
	Node * right;
public :
	Node(int d = 0, Node* l = NULL, Node * r = NULL)
		:data(d), left(l), right(r) {}
	void setData(int d) { data = d; }
	void setLeft(Node* l) { left = l; }
	void setRight(Node* r) { right = r; }
	int getData() { return data; }
	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	bool isLeaf() { return left == NULL && right == NULL; }
};