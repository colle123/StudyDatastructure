#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct ary {

	char data[SIZE];
	struct ary_node* next;

}Arr;

void createNode(Arr* H, Arr* T) {

	Arr* newNode = (Arr*)malloc(sizeof(Arr));
	if (newNode == NULL) return;
	
	char temp[SIZE];

	while (1) {

		printf("알파벳을 입력하세요 : ");
		scanf("%c", &temp);

		if ((temp >= 'A' && temp <= 'Z')) {

			strcpy(newNode->data, temp);
			newNode->next = NULL;
			break;
		}

		else if ((temp >= 'a' && temp <= 'z')) {

			strcpy(newNode->data, temp);
			newNode->next = NULL;
			break;
		}

		else {

			printf("문자를 입력해주세요.\n");
			continue;
		}
	}

	if (H == NULL) {

		newNode = H->next;
		T = newNode;
	}

	else {

		newNode->next = T->next;
		T->next = newNode;
	}

}

void InserSort(int arr[], int n) {

	int i, j;
	int insData;

	for (i = 1; i < n; i++) {

		insData = arr[i];

		for (j = i - 1; j >= 0; j--) {

			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = insData;
	}
}

void printNode(Arr* H) {                                         

	Arr* curr = H->next;

	while (curr != NULL) {

		printf("%d\n", curr->data);

		curr = curr->next;
	}

}

int main() {

	Arr* head = NULL;
	Arr* tail = NULL;

	createNode(head, tail);
	
	printNode(head);

	return 0;
}