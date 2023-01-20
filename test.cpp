#include"test.h"

//実体
TestSingleton::TestSingleton()
{}
TestSingleton::~TestSingleton()
{}


TestSingleton* TestSingleton::GetInstance() {
	//関数内static変数として宣言する
	static TestSingleton instance;

	return &instance;
}

void TestSingleton::Update(int &x)
{
	x++;
}
