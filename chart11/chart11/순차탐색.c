#include <stdio.h>

int LSearch(int *ary, int adata, int size) {

	int i;

	for (i = 0; i < size ; i++) {

		if (ary[i] == adata)
			return i + 1;
	}

	return 0;
}

int main() {

	int num;

	int ary[] = { 1, 5, 9, 3, 8, 7, 4, 2 };
	printf("ã�� ���ڸ� �Է��ϼ��� : ");
	scanf("%d", &num);

	int Size = (sizeof(ary) / sizeof(ary[0]));

	if (LSearch(ary, num, Size)) printf("%d��(��) %d��°�� ��ġ�ϰ� �ֽ��ϴ�.\n", num, LSearch(ary, num, Size));

	else printf("%d�� �������� �ʽ��ϴ�.\n", num);

	//printf("%d�� �������� �ʽ��ϴ�.\n", num);

	return 0;
}