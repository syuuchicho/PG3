#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;


typedef struct cell
{
	char str[8];
	struct cell* next;
}CELL;

void create(CELL* endCell, const char* buf);	//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾�@
void index(CELL* head);	//�ꗗ��\������֐��̃v���g�^�C�v�錾

int main()
{
	char str[8];

	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("��������͂��Ă�������\n");
		scanf_s("%s", str,8);

		//�Ō���ɃZ����ǉ�
		create(&head, str);

		printf("�ꗗ\n");
		//���X�g�ꗗ�̕\��
		index(&head);
	}

	return 0;
}

void create(CELL* endCell, const char*buf)
{
	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, 8, buf);
	newCell->next = nullptr;

	//�Ō�(�ŐV)�̃Z���̃A�h���X��1�߂̏����͈������玝���Ă���
	//���X�g�̂����ŏ��ɃZ���̃A�h���X���Y������
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