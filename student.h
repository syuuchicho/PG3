#pragma once
class Student
{
protected:
public:
	static int studentCount;
	Student() { studentCount++; }
	~Student() { studentCount--; }
};

