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

	// 4 x 3 x 2 x 1 �� �������� ����ϴ� �ڵ�

	int n;
	int result;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &n);
	result = Factorial(n);

	printf("����� : ");
	printf("%d\n", result);
}