#include<stdio.h>
#include<stdlib.h>
#include"test.h"

int main()
{
	int x = 0;
	printf("x=%d\n", x);
	//�C���X�^���X���擾���āA�����g�p
	TestSingleton::GetInstance()->Update(x);
	printf("x=%d\n", x);

	return 0;
}

