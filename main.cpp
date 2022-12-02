#include<stdio.h>
#include<stdlib.h>


using namespace std;


typedef struct cell
{
	int val;
	struct cell* next;
}CELL;

void create(CELL* head, int val,int &no);	//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾�@
void index(CELL* head,int& no);	//�ꗗ��\������֐��̃v���g�^�C�v�錾

int main()
{
	int val;
	int no = 0;
	

	CELL head;
	head.next = nullptr;

	while (true)
	{
		no = 0;
		printf("�D���Ȑ�������͂��Ă�������\n");
		scanf_s("%d", &val);

		//�Ō���ɃZ����ǉ�
		create(&head, val,no);
		//printf("�ꗗ\n");
		//���X�g�ꗗ�̕\��
		index(&head,no);
	
	}

	return 0;
}

void create(CELL* head, int val, int& no)
{

	CELL* beta;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	beta = (CELL*)malloc(sizeof(CELL));

	beta->val = val;
	beta->next = nullptr;

	//�Ō�(�ŐV)�̃Z���̃A�h���X��1�߂̏����͈������玝���Ă���
	//���X�g�̂����ŏ��ɃZ���̃A�h���X���Y������
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