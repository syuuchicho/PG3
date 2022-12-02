#include<stdio.h>
#include<stdlib.h>


using namespace std;


typedef struct cell
{
	int val;
	struct cell* next;
}CELL;

void create(CELL* head, int val,int &no);	//データを追加する関数のプロトタイプ宣言　
void index(CELL* head,int& no);	//一覧を表示する関数のプロトタイプ宣言

int main()
{
	int val;
	int no = 0;
	

	CELL head;
	head.next = nullptr;

	while (true)
	{
		no = 0;
		printf("好きな数字を入力してください\n");
		scanf_s("%d", &val);

		//最後尾にセルを追加
		create(&head, val,no);
		//printf("一覧\n");
		//リスト一覧の表示
		index(&head,no);
	
	}

	return 0;
}

void create(CELL* head, int val, int& no)
{

	CELL* beta;
	//新規作成するセル分のメモリを確保する
	beta = (CELL*)malloc(sizeof(CELL));

	beta->val = val;
	beta->next = nullptr;

	//最後(最新)のセルのアドレスの1つめの処理は引数から持ってきた
	//リストのうち最初にセルのアドレスが該当する
	while (head->next != nullptr) {
		head = head->next;
	}
	head->next = beta;
}

void index(CELL* head,int& no) {
	
	printf("[");
	while (head->next != nullptr) {
		head = head->next;
		
		if (no!=0)
		{
			printf(",");
		}
		printf("%d", head->val);
		no++;
	}
	printf("]\n");
	no++;
}