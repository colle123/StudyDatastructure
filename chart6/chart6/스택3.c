#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int element;

typedef struct node {    // 리스트 구조체

	element data;
	struct node* link;

}Node;

typedef struct {         // 헤드 구조체

	Node* head;

}HStack;

HStack* createHead();
bool isEmpty(HStack*);
//bool isFull(HStack*);
void push(HStack*, element);
element pop(HStack*);
element peek(HStack*);

int main() {

	HStack* H = createHead();

	printf("============== 입력 ================\n");

	push(H, 10);
    push(H, 20);
	push(H, 30);


	printf("\n============== 출력 ================\n");

	printf("%d\n", pop(H));
	printf("%d\n", pop(H));
    printf("%d\n", pop(H));
	printf("%d\n", pop(H));

	return 0;
}

HStack* createHead() {

	HStack* h = (HStack*)malloc(sizeof(HStack));
	if (h == NULL) exit(1);

	h->head = NULL;

	return h;
}

bool isEmpty(HStack* phstack) {

	if (phstack->head == NULL)
		return true;
	else
		return false;
}

void push(HStack* phstack, element value) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->data = value;
	newNode->link = phstack->head;

	phstack->head = newNode;

	printf("%d\n", newNode->data);
}

element pop(HStack* phstack) {

	if (isEmpty(phstack)) {
		printf("STACK IS EMPTY!!\n");
		exit(1);
	}

	else {

		Node* temp = phstack->head;
		element temp_data = phstack->head->data;

		phstack->head = phstack->head->link;
		free(temp);

		return temp_data;
	}
}

element peek(HStack* phstack) {

	if (isEmpty(phstack)) {
		printf("STACK IS EMPTY!!\n");
		exit(1);
	}

	else return phstack->head->data;
}