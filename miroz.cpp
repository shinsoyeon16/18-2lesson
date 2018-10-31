#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <iostream>
#include<stack>
#include"Location2D.h"
using namespace std;

const int MAZE_SIZE = 6;//상수 정수형 선언
const int MAZE_COL_SIZE = 14;

char map[MAZE_SIZE][MAZE_COL_SIZE] = //지도 를 배열로 표현
{
	{0},
};
void setMap() {
	FILE * fp = fopen("miromap.txt", "rt");
	if (fp == NULL) {
		cout << "파일 입출력 에러" << endl;
		exit(1);
	}
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_COL_SIZE; j++) {
			map[i][j]=fgetc(fp);
		}
	}
	fclose(fp);
}
bool isValidLoc(int r, int c) //위치탐색 갈수있는곳 참,거짓으로 반환
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_COL_SIZE)return false;//(r,c가 0보다작거나 r,c가 미로크기보다 크거나 같으면 거짓을 반환하여라 )
	else return map[r][c] == '0' || map[r][c] == 'x';//그렇지않고 0과x면 참 반환 그외 거짓 반환
}// 확인만을 위한 함수

int main() {
	setMap();
	stack<Location2D>locStack;//Location2D형의 스택인 록스택객체 선언
	Location2D entry(1, 0);//시작의 위치를 나타내는 객체 선언
	locStack.push(entry);//록스택객체에 시작위치를 나타내는 객체를 넣어라

	while (locStack.empty() == false)//스택이 비어있지 않다면 반복해라 
	{
		Location2D here = locStack.top();//here(현재위치)객체 선언 그후 stack맨위값을 here에 넣어라  //좌표  이동
		locStack.pop();//이동했으면 빠져라

		int r = here.row;
		int c = here.col;
		printf("(%d,%d)", r, c);
		if (map[r][c] == 'x')//반복문을 나가기 위한 탈출 조건 
		{
			printf("미로 탐색 성공\n");
			return 0;

		}

		else {//x가 아니여서 실행 . 탐색및 지나온자리 체크
			map[r][c] = '.';//지나온자리 .으로 바꿔라
			if (isValidLoc(r - 1, c))locStack.push(Location2D(r - 1, c));//좌
			if (isValidLoc(r + 1, c))locStack.push(Location2D(r + 1, c));//우
			if (isValidLoc(r ,c-1))locStack.push(Location2D(r, c - 1));//상
			if (isValidLoc(r ,c+1))locStack.push(Location2D(r, c + 1));//하
		}
	}
	printf("미로탐색실패\n");
	return 0;
}