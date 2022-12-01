#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;


typedef struct cell
{
	char str[9];//漢字4文字まで
	struct cell* next;
}CELL;

typedef struct cell2
{
	int val;
	struct cell2* next;
}CELL2;

void createName(CELL* endCell, const char* buf);	//データを追加する関数のプロトタイプ宣言　
void createDate(CELL2* head, int val);
void indexName(CELL* head);	//一覧を表示する関数のプロトタイプ宣言
void indexDate(CELL2* head);	//一覧を表示する関数のプロトタイプ宣言

int main()
{
	char str[9];
	int val;

	CELL head;
	head.next = nullptr;
	CELL2 head2;
	head2.next = nullptr;

	while (true)
	{
		printf("氏名を入力してください\n");
		scanf_s("%s", str,9);
		//最後尾にセルを追加
		createName(&head, str);
		
		printf("貸出日を入力してください\n");
		scanf_s("%d", &val);
		//最後尾にセルを追加
		createDate(&head2,val);

		printf("返却日を入力してください\n");
		scanf_s("%d", &val);
		//最後尾にセルを追加
		createDate(&head2, val);

		printf("一覧\n");
		//リスト一覧の表示
		indexName(&head);
		indexDate(&head2);
	}

	return 0;
}

void createName(CELL* endCell, const char*buf)
{
	CELL* newCell;
	//新規作成するセル分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, 9, buf);
	newCell->next = nullptr;

	//最後(最新)のセルのアドレスの1つめの処理は引数から持ってきた
	//リストのうち最初にセルのアドレスが該当する
	while (endCell->next != nullptr) {
		endCell = endCell->next;
	}
	endCell->next = newCell;
}

void createDate(CELL2* head, int val)
{
	CELL2* beta;
	//新規作成するセル分のメモリを確保する
	beta = (CELL2*)malloc(sizeof(CELL2));

	beta->val = val;
	beta->next = nullptr;

	//最後(最新)のセルのアドレスの1つめの処理は引数から持ってきた
	//リストのうち最初にセルのアドレスが該当する
	while (head->next != nullptr) {
		head = head->next;
	}
	head->next = beta;
}

void indexName(CELL* head) {
	while (head->next != nullptr) {
		head = head->next;
		printf("%s\n", head->str);
	}
}

void indexDate(CELL2* head) {
	while (head->next != nullptr) {
		head = head->next;
		printf("%d\n", head->val);
	}
}