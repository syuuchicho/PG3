#include<stdio.h>

//int calc(int a, int b){
//	return a + b;
//}
//
//float calc(float d, float e) {
//	return d + e + 10;
//}

template<typename Type>
Type add(Type a,Type b){
	return static_cast<Type>(a + b);
}

int main() {
	/*int x = 114;
	int y = 514;*/
	/*float l = 3.64f;
	float m = 3.64f;*/
	printf("%d\n", add<int>(114,514));
	printf("%f\n", add<float>(11.4f,51.4f));
	return 0;
	
}