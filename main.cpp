#include<stdio.h>
#include<stdlib.h>
#include"test.h"

int main()
{
	//インスタンスを取得して、すぐ使用
	TestSingleton::GetInstance()->Update();
	return 0;
}

