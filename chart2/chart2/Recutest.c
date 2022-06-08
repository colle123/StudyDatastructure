#include <stdio.h>


int Factorial(int a) {

	//int res = 1;
	//
	//for (int i = a; i >= 1; i--) {
	//	
	//	res = i * res;
	//}

	//return res;

	if (a == 0)
		return 1;
	else
		return a * Factorial(a - 1);
}

int main() {

	// 4 x 3 x 2 x 1 의 연산결과를 출력하는 코드

	int n;
	int result;

	printf("정수를 입력하세요 : ");
	scanf("%d", &n);
	result = Factorial(n);

	printf("결과값 : ");
	printf("%d\n", result);
}