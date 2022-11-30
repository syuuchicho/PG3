#include<stdio.h>
#include<stdlib.h>


using namespace std;


typedef struct cell
{
	int val;
	struct cell* next;
}CELL;

void create(CELL* head, int val);	//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾�@
void index(CELL* head);	//�ꗗ��\������֐��̃v���g�^�C�v�錾

int main()
{
	int val;

	CELL head;
	head.next = nullptr;

	while (true)
	{
		scanf_s("%d", &val);

		//�Ō���ɃZ����ǉ�
		create(&head, val);

		//���X�g�ꗗ�̕\��
		index(&head);
	}

	return 0;
}

void create(CELL*head,int val)
{
	CELL *beta;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	beta = (CELL*)malloc(sizeof(CELL));

	beta->val = val;
	beta->next = nullptr;

	//�Ō�(�ŐV)�̃Z���̃A�h���X��1�߂̏����͈������玝���Ă���
	//���X�g�̂����ŏ��ɃZ���̃A�h���X���Y������
	while (head->next!=nullptr){
		head = head->next;
	}
	head->next = beta;
}

void index(CELL* head) {
	while (head->next!=nullptr){
		head = head->next;
		printf("%d\n", head->val);
	}
}