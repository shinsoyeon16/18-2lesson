#include "test1022-Tree.h"

void main() {

	Tree tree; //트리 객체 생성

	//노드에 값 저장 후 트리 연결
	Node* d= new Node('D', NULL, NULL);
	Node* e= new Node('E', NULL, NULL);
	Node* b = new Node('B', d, e);
	Node* f= new Node('F', NULL, NULL);
	Node* c= new Node('C', f, NULL);
	Node* a= new Node('A', b, c);
	tree.setRoot(a); //a를 루트로 설정

	//트리 순회
	tree.inorder(); //중위식 순회
	tree.preorder(); //전위식 순회
	tree.postorder(); //후위식 순회
	tree.levelorder(); //레벨 순회

	//트리 연산
	printf(" 전체노드의 개수 = %d\n", tree.getCount());
	printf(" 자식노드의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree.getHeight());
}
