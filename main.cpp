#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<functional>
#include<stdlib.h>
#include<time.h>

typedef void (*PFunc)(int*);

//�R�[���o�b�N�֐�
void DispResult(int* s) {
	printf("���ʂ�.....", *s);
}

void setTimeout(PFunc p, int second) {
	Sleep(second * 1000);//3�b�҂�

	p(&second);
}

int main(int argc, const char* argv[])
{
	srand(time(nullptr));
	int num = rand() % 6 + 1;	//���I
	int c = 0;
	int time = 180;
	int count = -1;
	int result = 0;

	//���͐���
	printf("���������P, ������������2����͂��Ă�������\n");

	PFunc p;
	p = DispResult;

	//����
	if (num % 2 == 0)
	{
		result = 2;//�����
	}
	else if (num % 2 == 1)
	{
		result = 1;//�����
	}
	scanf_s("%d", &c);

	setTimeout(p, 3);
	printf("%d\n", num);

	if (result == c)
	{
		printf("������I\n");
	}
	else
	{
		printf("�n�Y���I\n");
	}
	return 0;
}