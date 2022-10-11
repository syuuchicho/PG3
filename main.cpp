#include<stdio.h>
#include<typeinfo>
#include <iostream>
using namespace std;

template<typename T>
T Big(T a,T b)
{	
	if (static_cast<T> (a) > static_cast<T> (b))
	{
		return static_cast<T>(b);
	}
	else
	{
		return static_cast<T>(a);
	}
}

int main() 
{
	//		intŒ^‚Ì’l‚ğ”äŠr
	int x = 10;
	int y = 20;

	cout << "x:" << x << "‚Æy:" << y << "‚ğ”äŠr" << endl;
	auto a = Big(x, y);
	cout << "‘å‚«‚¢’l‚Í" << a << endl;
	cout << "a‚ÌŒ^:" << typeid(a).name() << endl;		//#include<typeinfo>‚ª•K—v

	//		floatŒ^‚Ì’l‚ğ”äŠr
	float z = 12.3f;
	float w = 45.6f;

	cout << "z:" << z << "‚Æw:" << w << "‚ğ”äŠr" << endl;
	auto b = Big(z, w);
	cout << "‘å‚«‚¢’l‚Í" << b << endl;
	cout << "b‚ÌŒ^:" << typeid(b).name() << endl;		//#include<typeinfo>‚ª•K—v

	return 0;
}