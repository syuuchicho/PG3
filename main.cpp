#include<stdio.h>
#include <iostream>

void drawImage() {
	
	std::cout << "‰æ‘œ‚ð•`‰æ" << std::endl;
}

int drawImage(int x, int y)
{
	std::cout << "‰æ‘œ‚ð•`‰æ",
	std::cout << " x : " << x,
	std::cout << " y : " << y<< std::endl;
	return 0;
}

int drawImage(int x, int y,int z)
{
	std::cout << "‰æ‘œ‚ð•`‰æ",
	std::cout << " x : " << x,
	std::cout << " y : " << y ,
	std::cout << " z : " << z << std::endl;
	return 0;
}

int main() {
	
	drawImage();
	drawImage(2, 4);
	drawImage(3, 6, 9);
	return 0;
}