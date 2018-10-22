#include "test1022-Tree.h"
#include "1022-Stack.h"
#include <iostream>
#include <cstdio>

Node * MakeExpTree(char exp[]) {
	Stack stack;
	Node * pnode;
	
	int expLen = strlen(exp);
	int i;
	
	for (i = 0; i < expLen; i++) {
		pnode = MakeExpTree();
		if (isdigit(exp[i]))
		{
			setData(pnode, exp[i] - '0');
		}
		else
		{
			Node()
		}
	}
}