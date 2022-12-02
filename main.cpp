#include<stdio.h>
#include<stdlib.h>

using namespace std;

//双方向リストの構造体の定義
typedef struct cell
{
	int val;
	struct cell* prev;
	struct cell* next;
}CELL;

void create(CELL* currentCell, int val);	//データを追加する関数のプロトタイプ宣言　
void index(CELL* endCell,int indexMenu);	//一覧を表示する関数のプロトタイプ宣言
CELL* getInsertCellAddress(CELL* endCELL, int iterator);

int main()
{
	int menu = 0;
	int indexMenu = 0;
	int iterator;			//何番目のセル
	int inputValue;			//挿入する値
	CELL* insertCell;

	//先頭のセルの宣言
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true)
	{
		switch (menu)
		{
		case 0:
			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");
			printf("3.要素の編集\n");
			printf("4.要素の削除\n");
			printf("5.要素の並び替え(オプション)\n\n");
			printf("--------------------------------------------\n");
			printf("操作を選択してください\n");
			scanf_s("%d", &menu);
			break;
		case 1:
			printf("要素の表示\n");
			printf("1.要素の一覧表示\n");
			printf("2.順番を指定して要素を表示\n");
			printf("9.要素操作に戻る\n\n");

			printf("操作を選択してください\n");
			scanf_s("%d", &indexMenu);
			if (indexMenu == 9)
			{
				menu = 0;
				break;
			}
			//リスト一覧の表示
			index(&head,indexMenu);
			break;
		case 2:
			printf("何番目のセルの後ろに挿入しますか?\n");
			scanf_s("%d", &iterator);
			printf("挿入する値を入力してください\n");
			scanf_s("%d", &inputValue);
			//任意のセルの後ろに追加
			insertCell = getInsertCellAddress(&head, iterator);
			create(insertCell, inputValue);
			menu = 0;
			break;
		default:
			break;
		}



	}
	return 0;
}

CELL* getInsertCellAddress(CELL* endCELL, int iterator) {
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
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

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void index(CELL* endCell,int indexMenu) {
	int no = 0;
	//nextに何か値が入っているかぎり出力
	printf("要素一覧:{\n");
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d:", no);
		//printf("%p\n", endCell->prev);
		printf("%d\n", endCell->val);//5桁まで右揃え
		//printf("(%p)\n", endCell);
		//printf("%p\n", endCell->next);
		no++;
	}
	/*if (endCell->next==nullptr)
	{
		printf("表示できる要素がありません\n");
	}*/
	printf("}\n\n");
	printf("要素数:%d\n\n", no);

}