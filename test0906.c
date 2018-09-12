//  ��ũ�ý��� �����		1. ���� �����		2. �����޸�(�����͹迭 ���)		3. ����ü�� int�� ������ char������ ��ȯ)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	int choice = 0;
	for(int a=0;a<100;a++)
	acc[a] = (Account *)malloc(sizeof(Account));
	FILE * fp = fopen("bank.txt", "rt"); //���� ����� ��Ʈ��
	if (fp == NULL) {
		printf("File is not exists!\n");
		return 0;
	}

	fscanf(fp, "%d", &numOfAccount);
	for (int i = 0; i < numOfAccount; i++) {
		fscanf(fp, "%s %s %d", acc[i]->id, acc[i]->pass, &acc[i]->balance);
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
				fprintf(fp, "%s %s %d\n", acc[i]->id, acc[i]->pass, acc[i]->balance);
			}
			fclose(fp);
			return 0;
		default:
			printf("Wrong input"); return 0;
		}
	} while (1);
}

void showMenu()
{
	printf("\n===Bank Service===\n 1. ȸ������\n 2. �α���\n 3. ����\n===Choice >> ");
}
void join()
{
	acc[numOfAccount] = (Account *)malloc(sizeof(Account));
	printf("===Join===\n");
	int i;
	do {
		printf("id : ");
		scanf("%s", acc[numOfAccount]->id);
		for (i = 0; i < numOfAccount; i++) {
			if (strcmp(acc[i]->id, acc[numOfAccount]->id) == 0) {
				printf("�̹� ���ԵǾ� �ִ� ȸ�� ���̵��Դϴ�. �ٽ��Է����ּ���\n");
				break;
			}
		}
		if (i == numOfAccount) break;
	} while (numOfAccount != 0);

	printf("password : ");
	scanf("%s", acc[numOfAccount]->pass);
	printf("balance : ");
	scanf_s("%d", &acc[numOfAccount]->balance);
	printf("join success!\n");
	numOfAccount++;
	

	FILE * fp = fopen("bank.txt", "wt");
	fprintf(fp, "%d\n", numOfAccount);
	for (int i = 0; i < numOfAccount; i++) {
		fprintf(fp, "%s %s %d\n", acc[i]->id, acc[i]->pass, acc[i]->balance);
	}
	fclose(fp);

	 fp = fopen("bank.txt", "rt"); 
	fscanf(fp, "%d", &numOfAccount);
	for (int i = 0; i < numOfAccount; i++) {
		fscanf(fp, "%s %s %d", acc[i]->id, acc[i]->pass, &acc[i]->balance);
	}
	fclose(fp);

}

void logIn()
{
	char id[10], pass[10];
	int i;
	printf("===Login===\nid : ");
	scanf("%s", id);
	printf("password : ");
	scanf("%s", pass);
	for (i = 0; i < numOfAccount; i++)
	{
		if (!strcmp(id, acc[i]->id) && !strcmp(pass, acc[i]->pass)) {
			printf("�α��� ����!\n");
			transaction(i);
		}
		else if (!strcmp(id, acc[i]->id)) {
			printf("��й�ȣ�� �ٸ��ϴ�. ");
		}
	}
	if (i == numOfAccount)
	{
		printf("�α��� ����!\n");
	}
}

void transaction(int i)
{
	char queryId[10];
	int select, money, j = 0;
	do {
		showBankMenu(i);
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf("Enter Deposit Money: ");
			scanf_s("%d", &money);
			acc[i]->balance += money;
			printf("%d �� �ԱݿϷ�.\n", money);
			break;
		case 2:
			printf("Enter Withdraw Money: ");
			scanf_s("%d", &money);
			if (acc[i]->balance < money) {
				printf("�ܾ� ����!\n");
				break;
			}
			acc[i]->balance -= money;
			printf("%d �� ��ݿϷ�.\n", money);
			break;
		case 3:
			do {
				printf("Enter Query Id: ");
				scanf("%s", queryId);
				if (!strcmp(queryId, acc[i]->id)) {
					printf("�ٽ� �Է��� �ֽʽÿ�.\n"); continue;
				}
				for (j = 0; j < numOfAccount; j++) {
					if (!strcmp(queryId, acc[j]->id)) {
						while (1) {
							printf("Enter Query Money: ");
							scanf_s("%d", &money);
							if (acc[i]->balance < money) {
								printf("�ܾ� ����!\n");
							}
							else break;
						}
						acc[i]->balance -= money;
						acc[j]->balance += money;
						printf("%s �Կ��� %d �� �۱� �Ϸ�.\n", acc[j]->id, money);
						break;
					}
				}

				if (strcmp(queryId, acc[j]->id)!=0) printf("�������� �ʴ� id �Դϴ�.\n");
				else break;
			} while (1);
			break;


		case 4:
			printf("�α׾ƿ� �Ϸ�!\n");
			return;
		default:
			printf("Wrong input"); return ;
		}
	} while (1);
}
void showBankMenu(int i)
{
	printf("\n===Bank Service===\n=== %s ȸ���� ȯ���մϴ�.===\n=== ���� �ܾ� : %d ===\n 1. �Ա�\n 2. ���\n 3. �۱�\n 4. �α׾ƿ�\n===Select >> ", acc[i]->id, acc[i]->balance);
}