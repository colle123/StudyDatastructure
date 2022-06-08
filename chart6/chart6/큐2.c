#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char element;
typedef struct node {     // ������

	element data;
	struct node* link;

}Node;

typedef struct {          // ť��ġ

	Node* rear;           // ť ��带 ����Ű�� ���(�Ա�)
	Node* front;          // ť ��带 ����Ű�� ���(�ⱸ)

}Qlink;


Qlink* createQ() {        // ť��ũ ���� �Լ�

	Qlink* ql = (Qlink*)malloc(sizeof(Qlink));
	if (ql == NULL) return;

	ql->front = NULL;
	ql->rear = NULL;

	return ql;
}

bool isEmpty(Qlink* apl) {


	if (apl->front == NULL) {
		//printf("QUEUE IS EMPTY!!\n");
		return true;
	}
	else 
		return false;
}

void enQueue(Qlink* apl, element value) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) exit(1);

	newNode->data = value;
	newNode->link = NULL;

	if (isEmpty(apl)) {

		apl->front = newNode;
		apl->rear = newNode;

	}

	else {

		apl->rear->link = newNode;
		apl->rear = newNode;
	
	}

}

element deQueue(Qlink* apl) {

	Node* delNode = NULL;
	element del_data;

	if (isEmpty(apl)) {
	
		printf("QUEUE IS EMPTY!!\n");
	
	}

	delNode = apl->front;
	del_data = delNode->data;

	apl->front = apl->front->link;
	if (apl->front == NULL) apl->rear = apl->front;
	free(delNode);

	return del_data;
}

void printQ(Qlink* apl) {

	Node* curr = apl->front;

	if (isEmpty(apl)) {

		printf("QUEUE IS EMPTY!!\n");

	}

	while (curr != NULL) {

		printf("%c ", curr->data);
		curr = curr->link;
	}

	
}

int main() {

	Qlink* q = createQ();

	printf("======== ���� �� ========\n");

	enQueue(q, 'A');
	enQueue(q, 'B');
	enQueue(q, 'C');
	enQueue(q, 'D');

	printQ(q);

	printf("\n======== ���� �� ========\n");

	deQueue(q);
	deQueue(q);
	deQueue(q);
	deQueue(q);

	//AlldeQueue(q);

	printQ(q);

	printf("%p  %p\n", q->front, q->rear);

	enQueue(q, 'E');

	printQ(q);

	return 0;
}
