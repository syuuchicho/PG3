#include<stdio.h>
#include<stdlib.h>

using namespace std;

//�o�������X�g�̍\���̂̒�`
typedef struct cell
{
	int val;
	struct cell* prev;
	struct cell* next;
}CELL;

void create(CELL* currentCell, int val);	//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾�@
void index(CELL* endCell,int indexMenu);	//�ꗗ��\������֐��̃v���g�^�C�v�錾
CELL* getInsertCellAddress(CELL* endCELL, int iterator);

int main()
{
	int menu = 0;
	int indexMenu = 0;
	int iterator;			//���Ԗڂ̃Z��
	int inputValue;			//�}������l
	CELL* insertCell;

	//�擪�̃Z���̐錾
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true)
	{
		switch (menu)
		{
		case 0:
			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
			printf("5.�v�f�̕��ёւ�(�I�v�V����)\n\n");
			printf("--------------------------------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &menu);
			break;
		case 1:
			printf("�v�f�̕\��\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.���Ԃ��w�肵�ėv�f��\��\n");
			printf("9.�v�f����ɖ߂�\n\n");

			printf("�����I�����Ă�������\n");
			scanf_s("%d", &indexMenu);
			if (indexMenu == 9)
			{
				menu = 0;
				break;
			}
			//���X�g�ꗗ�̕\��
			index(&head,indexMenu);
			break;
		case 2:
			printf("���Ԗڂ̃Z���̌��ɑ}�����܂���?\n");
			scanf_s("%d", &iterator);
			printf("�}������l����͂��Ă�������\n");
			scanf_s("%d", &inputValue);
			//�C�ӂ̃Z���̌��ɒǉ�
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
	//�V�K�쐬����Z�����̃��������m�ۂ���
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
	//next�ɉ����l�������Ă��邩����o��
	printf("�v�f�ꗗ:{\n");
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d:", no);
		//printf("%p\n", endCell->prev);
		printf("%d\n", endCell->val);//5���܂ŉE����
		//printf("(%p)\n", endCell);
		//printf("%p\n", endCell->next);
		no++;
	}
	/*if (endCell->next==nullptr)
	{
		printf("�\���ł���v�f������܂���\n");
	}*/
	printf("}\n\n");
	printf("�v�f��:%d\n\n", no);

}