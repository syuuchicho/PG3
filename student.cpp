#include "student.h"
Student::Student()
{
	////メンバ関数ポインタに関数のアドレスを代入する
	//pFunc = &Student::TestFunc1;
	////メンバ関数ポインタに入っている関数を呼び出す
	//(this->*pFunc)();
//メンバ関数ポインタに入っている関数を呼び出す
	(this->*pFunc[0])();

}

void (Student::* Student::pFunc[])() =
{
	&Student::Test1,	//要素番号0
	&Student::Test2		//要素番号1
};

void Student::Test1()
{
	(this->*pFunc[1])();
}

void Student::Test2()
{

}