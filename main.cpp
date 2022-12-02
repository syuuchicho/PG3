#include<stdio.h>
#include<stdlib.h>

using namespace std;


typedef struct cell
{
	int val;
	struct cell* prev;
	struct cell* next;
}CELL;

void create(CELL* currentCell, int val);	//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾�@
void index(CELL* endCell);	//�ꗗ��\������֐��̃v���g�^�C�v�錾
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
		printf("���Ԗڂ̃Z���̌��ɑ}�����܂���?\n");
		scanf_s("%d", &iterator);

		printf("�}������l����͂��Ă�������\n");
		scanf_s("%d", &inputValue);

		//�Ō���ɃZ����ǉ�
		insertCell = getInsertCellAddress(&head,iterator);
		create(insertCell,inputValue);

		printf("���͂��ꂽ�l�ꗗ\n");
		//���X�g�ꗗ�̕\��
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
	//�V�K�쐬����Z�����̃��������m�ۂ���
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
	//next�ɉ����l�������Ă��邩����o��
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		//printf("No.%d\n", no);
		printf("%p\n", endCell->prev);
		printf("%5d\n", endCell->val);//5���܂ŉE����
		printf("(%p)\n", endCell);
		printf("%p\n", endCell->next);
		no++;
	}
}