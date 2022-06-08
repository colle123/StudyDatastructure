#include <stdio.h>

int BSearch(int* ary, int alen, int akey) {

	int left = 0;
	int right = alen - 1;
	int mid;
	
	while (left <= right) {

		mid = (left + right) / 2;

		if (ary[mid] == akey)
			return mid;

		else {

			if (akey < ary[mid]) right = mid - 1;

			else left = mid + 1;
		}
	}

	return -1;
}

int main() {

	int ary[] = { 1, 3, 4, 5, 7, 8, 9 };
	int len = sizeof(ary) / sizeof(ary[0]);
	int key, idx;

	printf("검색값 입력 : ");
	scanf("%d", &key);

	idx = BSearch(ary, len, key);

	if (idx == -1) printf("없습니다.\n");
	else printf("key index : %d", idx);

	return 0;
}