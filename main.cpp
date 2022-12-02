#include<stdio.h>
#include<stdlib.h>

using namespace std;


typedef struct cell
{
	int val;
	struct cell* prev;
	struct cell* next;
}CELL;

void create(CELL* currentCell, int val);	//データを追加する関数のプロトタイプ宣言　
void index(CELL* endCell);	//一覧を表示する関数のプロトタイプ宣言
CELL* getInsertCellAddress(CELL* endCELL, int iterator);

int main()
{
	int iterator;
	int inputValue;
	CELL* insertCell;


	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true)
	{
		printf("何番目のセルの後ろに挿入しますか?\n");
		scanf_s("%d", &iterator);

		printf("挿入する値を入力してください\n");
		scanf_s("%d", &inputValue);

		//最後尾にセルを追加
		insertCell = getInsertCellAddress(&head,iterator);
		create(insertCell,inputValue);

		printf("入力された値一覧\n");
		//リスト一覧の表示
		index(&head);
	}
	return 0;
}

CELL* getInsertCellAddress(CELL* endCELL, int iterator) {
	for (int i = 0; i < iterator; i++){
		if (endCELL->next){
			endCELL = endCELL->next;
		}else{
			break;
		}
	}
	return endCELL;
}


void create(CELL* currentCell, int val)
{
	CELL* newCell;
	//新規作成するセル分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next){
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void index(CELL* endCell) {
	int no = 1;
	//nextに何か値が入っているかぎり出力
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		//printf("No.%d\n", no);
		printf("%p\n", endCell->prev);
		printf("%5d\n", endCell->val);//5桁まで右揃え
		printf("(%p)\n", endCell);
		printf("%p\n", endCell->next);
		no++;
	}
}