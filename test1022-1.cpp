#include "test1022-Tree.h"

void main() {

	Tree tree; //Ʈ�� ��ü ����

	//��忡 �� ���� �� Ʈ�� ����
	Node* d= new Node('D', NULL, NULL);
	Node* e= new Node('E', NULL, NULL);
	Node* b = new Node('B', d, e);
	Node* f= new Node('F', NULL, NULL);
	Node* c= new Node('C', f, NULL);
	Node* a= new Node('A', b, c);
	tree.setRoot(a); //a�� ��Ʈ�� ����

	//Ʈ�� ��ȸ
	tree.inorder(); //������ ��ȸ
	tree.preorder(); //������ ��ȸ
	tree.postorder(); //������ ��ȸ
	tree.levelorder(); //���� ��ȸ

	//Ʈ�� ����
	printf(" ��ü����� ���� = %d\n", tree.getCount());
	printf(" �ڽĳ���� ���� = %d\n", tree.getLeafCount());
	printf(" Ʈ���� ���� = %d\n", tree.getHeight());
}
