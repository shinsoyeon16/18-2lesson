#include <stdio.h>

int b()
{
	return 0;
}
int c()
{
	return 0;
}
int a()
{
	b();
	c();
	return 0;
}
int main()
{
	a();
	return 0;
}