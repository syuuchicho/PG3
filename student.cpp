#include "student.h"
Student::Student()
{
	////�����o�֐��|�C���^�Ɋ֐��̃A�h���X��������
	//pFunc = &Student::TestFunc1;
	////�����o�֐��|�C���^�ɓ����Ă���֐����Ăяo��
	//(this->*pFunc)();
//�����o�֐��|�C���^�ɓ����Ă���֐����Ăяo��
	(this->*pFunc[0])();

}

void (Student::* Student::pFunc[])() =
{
	&Student::Test1,	//�v�f�ԍ�0
	&Student::Test2		//�v�f�ԍ�1
};

void Student::Test1()
{
	(this->*pFunc[1])();
}

void Student::Test2()
{

}