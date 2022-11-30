#include<stdio.h>
#include <iostream>
#include<list>
using namespace std;

//�p��\�L
void Cout(list<const char*> a) {
	for (list<const char*>::iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		cout << *itr << endl;//�p��\�L
	}
}

int main()
{
	list<const char*> a{"Tokyo","Yurakucho","shimbashi","Hamamatsucho","Tamachi","Shinagawa","Osaki",
					"Gotanda","Meguro","Ebisu","Shibuya","Harajuku","Yoyogi","Shinjuku","Shin-Okubo","Takadanobaba","Mejiro",
					"Ikebukuro","Otsuka","Sugamo","Komagome","Tabata","Nippori","Uguisudani","Ueno","Okamachi",
					"Akihabara","Kanda\n"};

	printf("1970�N\n");
	Cout(a);//�p��\�L

	printf("2019�N\n");
	for (list<const char*>::iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		if (*itr=="Nippori")
		{
			itr=a.insert(itr,"Nishi-nippori");//�����闢��}��
			++itr;
		}
	}
	Cout(a);//�p��\�L

	printf("2022�N\n");
	for (list<const char*>::iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			itr = a.insert(itr, "TakanawaGateway");//���փQ�[�g�E�F�C��}��
			++itr;
		}
	}
	Cout(a);//�p��\�L

	return 0;
}