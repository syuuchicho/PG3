#include"test.h"
TestSingleton* TestSingleton::GetInstance() {
	//�֐���static�ϐ��Ƃ��Đ錾����
	static TestSingleton instance;

	return &instance;
}

void TestSingleton::Update()
{
	
}
