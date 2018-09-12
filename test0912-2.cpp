#include "stdafx.h"
#include <iostream>
using namespace std;

// 2. for, if, countinue 사용하여 1-100 까지 짝수만 출력하는 프로그램 작성

int main() {
for (int i = 1; i <= 100; i++) {
if (i % 2 == 1)
continue;
cout << " " << i;
}
}
