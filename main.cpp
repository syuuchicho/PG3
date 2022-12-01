#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;


typedef struct cell
{
	char str[9];//����4�����܂�
	struct cell* next;
}CELL;

typedef struct cell2
{
	int val;
	struct cell2* next;
}CELL2;

void createName(CELL* endCell, const char* buf);	//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾�@
void createDate(CELL2* head, int val);
void indexName(CELL* head);	//�ꗗ��\������֐��̃v���g�^�C�v�錾
void indexDate(CELL2* head);	//�ꗗ��\������֐��̃v���g�^�C�v�錾

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
		printf("��������͂��Ă�������\n");
		scanf_s("%s", str,9);
		//�Ō���ɃZ����ǉ�
		createName(&head, str);
		
		printf("�ݏo������͂��Ă�������\n");
		scanf_s("%d", &val);
		//�Ō���ɃZ����ǉ�
		createDate(&head2,val);

		printf("�ԋp������͂��Ă�������\n");
		scanf_s("%d", &val);
		//�Ō���ɃZ����ǉ�
		createDate(&head2, val);

		printf("�ꗗ\n");
		//���X�g�ꗗ�̕\��
		indexName(&head);
		indexDate(&head2);
	}

	return 0;
}

void createName(CELL* endCell, const char*buf)
{
	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, 9, buf);
	newCell->next = nullptr;

	//�Ō�(�ŐV)�̃Z���̃A�h���X��1�߂̏����͈������玝���Ă���
	//���X�g�̂����ŏ��ɃZ���̃A�h���X���Y������
	while (endCell->next != nullptr) {
		endCell = endCell->next;
	}
	endCell->next = newCell;
}

void createDate(CELL2* head, int val)
{
	CELL2* beta;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	beta = (CELL2*)malloc(sizeof(CELL2));

	beta->val = val;
	beta->next = nullptr;

	//�Ō�(�ŐV)�̃Z���̃A�h���X��1�߂̏����͈������玝���Ă���
	//���X�g�̂����ŏ��ɃZ���̃A�h���X���Y������
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