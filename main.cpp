#include<stdio.h>
#include<stdlib.h>
#include"test.h"

int main()
{
	//�C���X�^���X���擾���āA�����g�p
	TestSingleton::GetInstance()->Update();
	return 0;
}

