//  포인터와 배열
#include <stdio.h>
void init(int a[][5], int len);
void print(int a[][5], int len);
void swapArray(int a[][5], int len);
int main() {
	int arr[3][5];
	init(arr, 3);  // 0~14
	print(arr, 3);
	swapArray(arr, 3);
	print(arr, 3);
}
void init(int a[][5], int len)
{
	int x = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++, x++) {
			a[i][j] = x;
		}
	}
}
void print(int a[][5], int len)
{
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void swapArray(int a[][5], int len)
{
	int * start;
	int * end;
	int temp;
	start = &a[0][0];
	end = &a[len - 1][4];
	for (int i = 0; i <= len * 5 / 2; i++) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++; end--;
	}
}