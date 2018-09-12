// ���Ϸκ����� �����, ���� �޸� �Ҵ�
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
	printf("\n===Bank Service===\n 1. ȸ������\n 2. �α���\n 3. ����\n===Choice >> ");
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
				printf("�̹� ���ԵǾ� �ִ� ȸ�� ���̵��Դϴ�. �ٽ��Է����ּ���\n");
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
			printf("�α��� ����!\n");
			transaction(i);
		}
		else if (id == acc[i].id) {
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
			printf("%d �� �ԱݿϷ�.\n", money);
			break;
		case 2:
			printf("Enter Withdraw Money: ");
			scanf_s("%d", &money);
			if (acc[i].balance < money) {
				printf("�ܾ� ����!\n");
				break;
			}
			acc[i].balance -= money;
			printf("%d �� ��ݿϷ�.\n", money);
			break;
		case 3:
			do {
				printf("Enter Query Id: ");
				scanf_s("%d", &queryId);
				if (queryId == acc[i].id) {
					printf("�ٽ� �Է��� �ֽʽÿ�.\n"); continue;
				}
				for (j = 0; j < numOfAccount; j++) {
					if (queryId == acc[j].id) {
						while (1) {
							printf("Enter Query Money: ");
							scanf_s("%d", &money);
							if (acc[i].balance < money) {
								printf("�ܾ� ����!\n");
							}
							else break;
						}
						acc[i].balance -= money;
						acc[j].balance += money;
						printf("%d �Կ��� %d �� �۱� �Ϸ�.\n", acc[j].id, money);
						break;
					}
				}

				if (queryId != acc[j].id) printf("�������� �ʴ� id �Դϴ�.\n");
				else break;
			} while (1);
			break;


		case 4:
			printf("�α׾ƿ� �Ϸ�!\n");
			return;
		default:
			printf("Wrong input"); break;
		}
	} while (1);
}
void showBankMenu(int i)
{
	printf("\n===Bank Service===\n=== %d ȸ���� ȯ���մϴ�.===\n=== ���� �ܾ� : %d ===\n 1. �Ա�\n 2. ���\n 3. �۱�\n 4. �α׾ƿ�\n===Select >> ", acc[i].id, acc[i].balance);
}

// ���ڿ� ��
/* int test()
{
	char str1[10], str2[10];
	if (str1 == str2) // ���ڿ��� �ƴ� �ּҰ� ����
		str1 = "hello";

	strcpy(str1, str2); // str1�� str2�� �����ؼ� �ٿ��־��
	if (!strcmp(str1, str2)); //�� ���ڿ��� ������ �����
	strlen
}*/