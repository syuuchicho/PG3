#pragma once
class Student
{

public:
	Student();
	~Student();
	//���상���o�֐�
	void Test1();
	void Test2();
private:
	//�����o�֐��|�C���^
	static void (Student::* pFunc[])();
};

