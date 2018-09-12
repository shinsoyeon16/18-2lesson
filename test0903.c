// 야구게임
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int comp[3];
int user[3];
int count = 0;

void CompInit();
void ReadInput();
int CheckResult();

int main()
{
	srand(time(NULL));
	CompInit();
	while (1)
	{
		ReadInput();
		if (CheckResult() == TRUE) {
			printf("%d 번 시도에 성공!!!!", count);
			break;
		}
	}
	return 0;
}

void CompInit() {
	for (int i = 0; i < 3; i++) {
		comp[i] = (rand() % 10);

		for (int j = 0; j < i; j++) {
			if (comp[j] == comp[i]) {
				comp[i] = (rand() % 10);
			}
		}
	}
}
void ReadInput() {
	printf("입력 : ");
	scanf_s("%d %d %d", &user[0], &user[1], &user[2]);
	count++;
}
int CheckResult() {
	int strike = 0, ball = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (comp[i] == user[i]) {
				strike++; break;
			}
		else if (comp[i] == user[j]) ball++;
		}
	}
	if (strike == 3) return TRUE;
	printf("%d  Strike  %d Ball\n", strike, ball);
	return FALSE;
}