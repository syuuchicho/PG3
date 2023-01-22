#pragma once
class Student
{

public:
	Student();
	~Student();
	//自作メンバ関数
	void Test1();
	void Test2();
private:
	//メンバ関数ポインタ
	static void (Student::* pFunc[])();
};

