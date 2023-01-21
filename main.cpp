#include<iostream>
#include"student.h"
using namespace std;

//main.cpp‚ÌŠO‚ÅéŒ¾
int Student::studentCount;

int main()
{
	Student* student1 = new Student;//1
	Student* student2 = new Student;//2
	Student* student3 = new Student;//3

	cout << Student::studentCount << endl;

	delete student1;//3-1

	cout << Student::studentCount << endl;
	delete student2;//2-1
	delete student3;//1-1
	cout << Student::studentCount << endl;

	
	return 0;
}

