#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <iostream>
#include<stack>
#include"Location2D.h"
using namespace std;

const int MAZE_SIZE = 6;//��� ������ ����
const int MAZE_COL_SIZE = 14;

char map[MAZE_SIZE][MAZE_COL_SIZE] = //���� �� �迭�� ǥ��
{
	{0},
};
void setMap() {
	FILE * fp = fopen("miromap.txt", "rt");
	if (fp == NULL) {
		cout << "���� ����� ����" << endl;
		exit(1);
	}
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_COL_SIZE; j++) {
			map[i][j]=fgetc(fp);
		}
	}
	fclose(fp);
}
bool isValidLoc(int r, int c) //��ġŽ�� �����ִ°� ��,�������� ��ȯ
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_COL_SIZE)return false;//(r,c�� 0�����۰ų� r,c�� �̷�ũ�⺸�� ũ�ų� ������ ������ ��ȯ�Ͽ��� )
	else return map[r][c] == '0' || map[r][c] == 'x';//�׷����ʰ� 0��x�� �� ��ȯ �׿� ���� ��ȯ
}// Ȯ�θ��� ���� �Լ�

int main() {
	setMap();
	stack<Location2D>locStack;//Location2D���� ������ �Ͻ��ð�ü ����
	Location2D entry(1, 0);//������ ��ġ�� ��Ÿ���� ��ü ����
	locStack.push(entry);//�Ͻ��ð�ü�� ������ġ�� ��Ÿ���� ��ü�� �־��

	while (locStack.empty() == false)//������ ������� �ʴٸ� �ݺ��ض� 
	{
		Location2D here = locStack.top();//here(������ġ)��ü ���� ���� stack�������� here�� �־��  //��ǥ  �̵�
		locStack.pop();//�̵������� ������

		int r = here.row;
		int c = here.col;
		printf("(%d,%d)", r, c);
		if (map[r][c] == 'x')//�ݺ����� ������ ���� Ż�� ���� 
		{
			printf("�̷� Ž�� ����\n");
			return 0;

		}

		else {//x�� �ƴϿ��� ���� . Ž���� �������ڸ� üũ
			map[r][c] = '.';//�������ڸ� .���� �ٲ��
			if (isValidLoc(r - 1, c))locStack.push(Location2D(r - 1, c));//��
			if (isValidLoc(r + 1, c))locStack.push(Location2D(r + 1, c));//��
			if (isValidLoc(r ,c-1))locStack.push(Location2D(r, c - 1));//��
			if (isValidLoc(r ,c+1))locStack.push(Location2D(r, c + 1));//��
		}
	}
	printf("�̷�Ž������\n");
	return 0;
}