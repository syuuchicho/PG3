#include"test.h"
TestSingleton* TestSingleton::GetInstance() {
	//ŠÖ”“àstatic•Ï”‚Æ‚µ‚ÄéŒ¾‚·‚é
	static TestSingleton instance;

	return &instance;
}

void TestSingleton::Update()
{
	
}
