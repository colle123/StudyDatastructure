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
	printf("찾을 숫자를 입력하세요 : ");
	scanf("%d", &num);

	int Size = (sizeof(ary) / sizeof(ary[0]));

	if (LSearch(ary, num, Size)) printf("%d은(는) %d번째에 위치하고 있습니다.\n", num, LSearch(ary, num, Size));

	else printf("%d이 존재하지 않습니다.\n", num);

	//printf("%d이 존재하지 않습니다.\n", num);

	return 0;
}