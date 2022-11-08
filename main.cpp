#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<functional>
#include<stdlib.h>
#include<time.h>

typedef void (*PFunc)(int*);

//コールバック関数
void DispResult(int* s) {
	printf("結果は.....", *s);
}

void setTimeout(PFunc p, int second) {
	Sleep(second * 1000);//3秒待つ

	p(&second);
}

int main(int argc, const char* argv[])
{
	srand(time(nullptr));
	int num = rand() % 6 + 1;	//抽選
	int c = 0;
	int time = 180;
	int count = -1;
	int result = 0;

	//入力説明
	printf("奇数だったら１, 偶数だったら2を入力してください\n");

	PFunc p;
	p = DispResult;

	//入力
	if (num % 2 == 0)
	{
		result = 2;//偶を代入
	}
	else if (num % 2 == 1)
	{
		result = 1;//奇を代入
	}
	scanf_s("%d", &c);

	setTimeout(p, 3);
	printf("%d\n", num);

	if (result == c)
	{
		printf("当たり！\n");
	}
	else
	{
		printf("ハズレ！\n");
	}
	return 0;
}