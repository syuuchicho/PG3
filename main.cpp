#include<stdio.h>
#include<stdlib.h>
#include"test.h"

int main()
{
	int x = 0;
	printf("x=%d\n", x);
	//インスタンスを取得して、すぐ使用
	TestSingleton::GetInstance()->Update(x);
	printf("x=%d\n", x);

	return 0;
}

