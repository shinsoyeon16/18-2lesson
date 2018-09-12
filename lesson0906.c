// 파일로부터의 입출력, 동적 메모리 할당
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void showMenu();
void logIn();
void join();
void transaction(int i);
void showBankMenu(int i);

typedef struct account
{
	char id[10];
	char pass[10];
	int balance;
} Account;

Account * acc[100];
int numOfAccount = 0;

int main()
{
	//acc[0]->balance = 1000;
	//acc[50]->balance = 30;
	printf("Enter id, pass, balance : ");
	acc[numOfAccount] = (Account * ) malloc(sizeof(Account));
	scanf("%s %s %d", acc[numOfAccount]->id, acc[numOfAccount]->pass, &acc[numOfAccount]->balance);
	printf("%s %s %d", acc[numOfAccount]->id, acc[numOfAccount]->pass, acc[numOfAccount]->balance);
}
/* int main()
{
	int choice = 0;
	FILE * fp = fopen("bank.txt", "rt");
	if (fp == NULL) {
		printf("File not exists!\n");
		return 0;
	}
	fscanf(fp, "%d", &numOfAccount);

	for (int i = 0; i < numOfAccount; i++) {
		fscanf(fp, "%d %d %d", &acc[i].id, &acc[i].pass, &acc[i].balance);
	}
	fclose(fp);

	do {
		showMenu();
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			join(); break;
		case 2:
			logIn(); break;
		case 3:
			fp = fopen("bank.txt", "wt");
			fprintf(fp, "%d\n", numOfAccount);
			for (int i = 0; i < numOfAccount; i++) {
				fprintf(fp, "%d %d %d\n", acc[i].id, acc[i].pass, acc[i].balance);
			}
			return 0;
		default:
			printf("Wrong input"); break;
		}
	} while (1);
}

void showMenu()
{
	printf("\n===Bank Service===\n 1. 회원가입\n 2. 로그인\n 3. 종료\n===Choice >> ");
}
void join()
{
	printf("===Join===\n");
	int i;
	do {
		printf("id : ");
		scanf_s("%d", &acc[numOfAccount].id);
		for (i = 0; i < numOfAccount; i++) {
			if (acc[i].id == acc[numOfAccount].id) {
				printf("이미 가입되어 있는 회원 아이디입니다. 다시입력해주세요\n");
				break;
			}
		}
		if (i == numOfAccount) break;
	} while (numOfAccount != 0);

	printf("password : ");
	scanf_s("%d", &acc[numOfAccount].pass);
	printf("balance : ");
	scanf_s("%d", &acc[numOfAccount].balance);
	printf("join success!\n");
	numOfAccount++;
}

void logIn()
{
	int id, pass, i;
	printf("===Login===\nid : ");
	scanf_s("%d", &id);
	printf("password : ");
	scanf_s("%d", &pass);
	for (i = 0; i < numOfAccount; i++)
	{
		if (id == acc[i].id && pass == acc[i].pass) {
			printf("로그인 성공!\n");
			transaction(i);
		}
		else if (id == acc[i].id) {
			printf("비밀번호가 다릅니다. ");
		}
	}
	if (i == numOfAccount)
	{
		printf("로그인 실패!\n");
	}
}

void transaction(int i)
{
	int select, money, queryId, j = 0;
	do {
		showBankMenu(i);
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf("Enter Deposit Money: ");
			scanf_s("%d", &money);
			acc[i].balance += money;
			printf("%d 원 입금완료.\n", money);
			break;
		case 2:
			printf("Enter Withdraw Money: ");
			scanf_s("%d", &money);
			if (acc[i].balance < money) {
				printf("잔액 부족!\n");
				break;
			}
			acc[i].balance -= money;
			printf("%d 원 출금완료.\n", money);
			break;
		case 3:
			do {
				printf("Enter Query Id: ");
				scanf_s("%d", &queryId);
				if (queryId == acc[i].id) {
					printf("다시 입력해 주십시오.\n"); continue;
				}
				for (j = 0; j < numOfAccount; j++) {
					if (queryId == acc[j].id) {
						while (1) {
							printf("Enter Query Money: ");
							scanf_s("%d", &money);
							if (acc[i].balance < money) {
								printf("잔액 부족!\n");
							}
							else break;
						}
						acc[i].balance -= money;
						acc[j].balance += money;
						printf("%d 님에게 %d 원 송금 완료.\n", acc[j].id, money);
						break;
					}
				}

				if (queryId != acc[j].id) printf("존재하지 않는 id 입니다.\n");
				else break;
			} while (1);
			break;


		case 4:
			printf("로그아웃 완료!\n");
			return;
		default:
			printf("Wrong input"); break;
		}
	} while (1);
}
void showBankMenu(int i)
{
	printf("\n===Bank Service===\n=== %d 회원님 환영합니다.===\n=== 현재 잔액 : %d ===\n 1. 입금\n 2. 출금\n 3. 송금\n 4. 로그아웃\n===Select >> ", acc[i].id, acc[i].balance);
}

// 문자열 비교
/* int test()
{
	char str1[10], str2[10];
	if (str1 == str2) // 문자열이 아닌 주소값 비교임
		str1 = "hello";

	strcpy(str1, str2); // str1에 str2를 복사해서 붙여넣어라
	if (!strcmp(str1, str2)); //두 문자열이 같으면 실행됨
	strlen
}*/