#include"test.h"

//À‘Ì
TestSingleton::TestSingleton()
{}
TestSingleton::~TestSingleton()
{}


TestSingleton* TestSingleton::GetInstance() {
	//ŠÖ”“àstatic•Ï”‚Æ‚µ‚ÄéŒ¾‚·‚é
	static TestSingleton instance;

	return &instance;
}

void TestSingleton::Update(int &x)
{
	x++;
}
