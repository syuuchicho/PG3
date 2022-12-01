#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;


typedef struct cell
{
	char str[8];
	struct cell* next;
}CELL;

void create(CELL* endCell, const char* buf);	//データを追加する関数のプロトタイプ宣言　
void index(CELL* head);	//一覧を表示する関数のプロトタイプ宣言

int main()
{
	char str[8];

	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("数字を入力してください\n");
		scanf_s("%s", str,8);

		//最後尾にセルを追加
		create(&head, str);

		printf("一覧\n");
		//リスト一覧の表示
		index(&head);
	}

	return 0;
}

void create(CELL* endCell, const char*buf)
{
	CELL* newCell;
	//新規作成するセル分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, 8, buf);
	newCell->next = nullptr;

	//最後(最新)のセルのアドレスの1つめの処理は引数から持ってきた
	//リストのうち最初にセルのアドレスが該当する
	while (endCell->next != nullptr) {
		endCell = endCell->next;
	}
	endCell->next = newCell;
}

void index(CELL* head) {
	while (head->next != nullptr) {
		head = head->next;
		printf("%s\n", head->str);
	}
}