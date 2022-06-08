#include <stdio.h>

void Recursive(int num) {

	if (num <= 0) // 기저조건이라고하며 이게 없으면 재귀함수가 무한루프에 빠짐. 중요!
		return;
	printf("Recursive call! %d \n", num);
	Recursive(num - 1);
}

int main(){

	Recursive(3);
	return 0;

}