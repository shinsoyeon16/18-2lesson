#include "stdafx.h"
#include <iostream>
using namespace std;

// 2. for, if, countinue ����Ͽ� 1-100 ���� ¦���� ����ϴ� ���α׷� �ۼ�

int main() {
for (int i = 1; i <= 100; i++) {
if (i % 2 == 1)
continue;
cout << " " << i;
}
}
