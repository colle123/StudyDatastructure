#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

	int data;
	struct _node* next;

}Node;

void addNode(Node* h, int d) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = d;
	newNode->next = NULL;

	newNode->next = h->next; // �ι�° ��带 ����Ű�� �Ѵ�.
	h->next = newNode;       // ù��° ���� ��ġ��Ų��.
}

void printNode(Node* h) {

	Node* curr = h->next;

	while (curr != NULL) {

		printf("%d\n", curr->data);
		curr = curr->next;
	}

}
int main() {

	Node* head = (Node*)malloc(sizeof(Node));

	head->next = NULL;

	addNode(head, 10);
	addNode(head, 20);
	addNode(head, 30);
	addNode(head, 40);

	printNode(head);

	return 0;
}