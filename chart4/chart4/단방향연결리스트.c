#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

	int data;
	struct _node* next;
}Node;

void pre_insertNode(Node* h, int d) { // 전위 삽입 노드

	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) return;

	newNode->data = d;
	newNode->next = NULL;

	newNode->next = h->next; 
	h->next = newNode;
}

void rear_insertNode(Node* h, int d) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->data = d;
	newNode->next = NULL;

	Node* curr = h->next;

	if (curr == NULL)
		h->next = newNode;

	else {
		while (curr->next!= NULL) {

			curr = curr->next;
		}

		curr->next = newNode;
	}
}

void printNode(Node* h) {

	Node* curr = h->next;

	while (curr != NULL) {

		printf("%d\n", curr->data);
		curr = curr->next;
	}

}

void freeNode(Node* h) {

	Node* curr = h->next;

	while (curr != NULL) {

		h->next = curr->next;
		free(curr);
		curr = h->next;
		
	}
}

Node* searchNode(Node* h, int d) {

	Node* curr = h->next;

	while (curr != NULL) {

		if (curr->data == d)
			return curr;

		curr = curr->next;
	}
	
	printf("해당 노드를 찾을 수 없어 NULL 값을 반환합니다.\n");

	return NULL;
}

void delNode(Node* target, Node* h) {

	Node* curr = h->next;
	Node* delNode = NULL;

	if (curr->data == target->data) {

		h->next = curr->next;
		free(curr);

	}

	else {
		while (curr->next != NULL) {

			if (curr->next->data == target->data) {

				delNode = curr->next;
				curr->next = curr->next->next;
				free(delNode);
				break;
			}

			curr = curr->next;
		}
	}

}

void middle_insertNode(Node* h, Node* s, int d) {

	Node* curr = h->next;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;
	
	newNode->data = d;
	newNode->next = NULL;

	while (curr != NULL) {

		if (curr->data == s->data) {

			newNode->next = curr->next;
			curr->next = newNode;
			
			break;
		}

		curr = curr->next;
	}
}

int main() {

	Node* Head = (Node*)malloc(sizeof(Node));
	if (Head != NULL) Head->next = NULL;

	pre_insertNode(Head, 40);
	rear_insertNode(Head, 50);
	pre_insertNode(Head, 30);
	rear_insertNode(Head, 60);
	rear_insertNode(Head, 70);
	pre_insertNode(Head, 20);
	pre_insertNode(Head, 10);
	middle_insertNode(Head, searchNode(Head, 10), 15);
	middle_insertNode(Head, searchNode(Head, 20), 25);
	middle_insertNode(Head, searchNode(Head, 30), 35);
	middle_insertNode(Head, searchNode(Head, 40), 45);
	middle_insertNode(Head, searchNode(Head, 50), 55);
	middle_insertNode(Head, searchNode(Head, 60), 65);
	middle_insertNode(Head, searchNode(Head, 70), 75);

	printf("==== 삭제전 ====\n");
	printNode(Head);

	freeNode(Head);

	printf("==== 삭제후 ====\n");
	printNode(Head);

	return 0;
}