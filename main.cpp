#include<stdio.h>
#include <iostream>
#include<vector>
#include<list>
using namespace std;

//�p��\�L
void Cout(list<string> a) {
	for (list<string>::iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		cout << *itr << endl;//�p��\�L
	}
}

int main()
{
	list<string> a{"Tokyo","Yurakucho","shimbashi","Hamamatsucho","Tamachi","Shinagawa","Osaki",
					"Gotanda","Meguro","Ebisu","Shibuya","Harajuku","Yoyogi","Shinjuku","Shin-Okubo","Takadanobaba","Mejiro",
					"Ikebukuro","Otsuka","Sugamo","Komagome","Tabata","Nippori","Uguisudani","Ueno","Okamachi",
					"Akihabara","Kanda\n"};

	printf("1970�N\n");
	Cout(a);//�p��\�L

	printf("2019�N\n");
	for (list<string>::iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		if (*itr=="Nippori")
		{
			itr=a.insert(itr,"Nishi-nippori");//�����闢��}��
			++itr;
		}
	}
	Cout(a);//�p��\�L

	printf("2022�N\n");
	for (list<string>::iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			itr = a.insert(itr, "TakanawaGateway");//�����闢��}��
			++itr;
		}
	}
	Cout(a);//�p��\�L

	return 0;
}