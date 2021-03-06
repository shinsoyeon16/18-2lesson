
#include <stdio.h>
void multiple(int *x);

// 매개변수의 복사와 참조(포인터)
/* int main() {

	int a = 10;
	int * pa = &a;
	//int * pa;
	//pa = &a;

	//pa++;
	//(*pa)++;


	multiple(pa);

	printf("%d ", a);
	printf("%p", pa);
	return 0;
}
void multiple(int *x) {
	*x = *x * 2;
}
void mulArray(int * x) { // ( int x[])
	x[3] = 100;
}
*/

// 구조체 (은행회원 예제)
void showMenu();
void logIn();
void join();
void transaction(int i);
void showBankMenu(int i);

typedef struct account
{
	int id;
	int pass;
	int balance;
} Account;
// typedef struct account Account;
 /* int main()
{
	struct account Account[10]; 
	struct account a;
	struct account * pa = &a;
	
	a.balance = 2000;
	(*pa).balance = 3000; 
	// pa->balance =  3000;

	Account[0].balance = 1000;
}*/

Account acc[10];
int numOfAccount = 0;

int main()
{
	int choice = 0;

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
	printf("===Join===\nid : ");
	scanf_s("%d", &acc[numOfAccount].id);
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
			while (1) {
				printf("Enter Query Id: ");
				scanf_s("%d", &queryId);
				for (int j = 0; j < numOfAccount; j++)
				{
					if (acc[j].id == queryId) {
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
				printf("존재하지 않는 id 입니다.\n");
			}
			break;

			
		case 4:
			printf("로그아웃 완료!\n");
			return 0;
		default:
			printf("Wrong input"); break;
		}
	} while (1);
}
void showBankMenu(int i)
{
	printf("\n===Bank Service===\n=== %d 회원님 환영합니다.===\n=== 현재 잔액 : %d ===\n 1. 입금\n 2. 출금\n 3. 송금\n 4. 로그아웃\n===Select >> ", acc[i].id, acc[i].balance);
}
