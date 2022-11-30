#include<stdio.h>
#include <iostream>
#include<list>
using namespace std;

//英語表記
void Cout(list<const char*> a) {
	for (list<const char*>::iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		cout << *itr << endl;//英語表記
	}
}

int main()
{
	list<const char*> a{"Tokyo","Yurakucho","shimbashi","Hamamatsucho","Tamachi","Shinagawa","Osaki",
					"Gotanda","Meguro","Ebisu","Shibuya","Harajuku","Yoyogi","Shinjuku","Shin-Okubo","Takadanobaba","Mejiro",
					"Ikebukuro","Otsuka","Sugamo","Komagome","Tabata","Nippori","Uguisudani","Ueno","Okamachi",
					"Akihabara","Kanda\n"};

	printf("1970年\n");
	Cout(a);//英語表記

	printf("2019年\n");
	for (list<const char*>::iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		if (*itr=="Nippori")
		{
			itr=a.insert(itr,"Nishi-nippori");//西日暮里を挿入
			++itr;
		}
	}
	Cout(a);//英語表記

	printf("2022年\n");
	for (list<const char*>::iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			itr = a.insert(itr, "TakanawaGateway");//高輪ゲートウェイを挿入
			++itr;
		}
	}
	Cout(a);//英語表記

	return 0;
}