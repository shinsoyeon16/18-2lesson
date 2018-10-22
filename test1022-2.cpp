#include "test1022-Tree.h"

void main() {

	Tree tree; //트리 객체 생성

	//노드에 값 저장 후 트리 연결
	Node* n1 = new Node(8, NULL, NULL);
	Node* n2 = new Node(3, NULL, NULL);
	Node* n3 = new Node('+', n1,n2);
	Node* n4 = new Node(7, NULL, NULL);
	Node* n5 = new Node('*', n4, n3);
	Node* n6 = new Node(9, NULL, NULL);
	Node* n7 = new Node('/', n5, n6);
	Node* n8 = new Node(1, NULL, NULL);
	Node* n9 = new Node('-', n7,n8);
	tree.setRoot(n9); 
	printf(" 계산 결과 = %d\n", tree.evaluate());

}
