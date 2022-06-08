/* ��������Ʈ �迭���� */

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10

typedef int element;

typedef struct {

	int top;
	element stack[STACK_SIZE];
}STACK;

void initSTACK(STACK*);
bool isEmpty(STACK*);
bool isFull(STACK*);
void push(STACK*, element);
element pop(STACK*);
element peek(STACK*);


int main() {

	STACK S;
	initSTACK(&S);

	printf("========== �Է� ==========\n\n");

	push(&S, 10);                 // stack[0]�� 10�� �Էµǰ� top�� 0�� ��  ���� 10
	push(&S, 20);                 // stack[1]�� 20�� �Էµǰ� top�� 1�� ��  ���� 10 20
	push(&S, 30);                 // stack[2]�� 30�� �Էµǰ� top�� 2�� ��  ���� 10 20 30

	printf("\n========== ��� ==========\n\n");
	pop(&S);                      // stack[2]�� �ִ� 30�� ��µǰ� top�� 1�̵� ���� 10 20
	pop(&S);                      // stack[1]�� �ִ� 20�� ��µǰ� top�� 0�̵� ���� 10
	pop(&S);                      // stack[0]�� �ִ� 10�� ��µǰ� top�� -1�̵� ���� empty

	return 0;
}

void initSTACK(STACK* pstack) {   // stack�� top�� -1�� �ʱ�ȭ���Ѽ� ����ִ� ���·� ��������

	pstack->top = -1;
}

bool isEmpty(STACK* pstack) {

	if (pstack->top <= -1) {
		printf("STACK IS EMPTY!!\n");
		return true;
	}

	else
		return false;
}

bool isFull(STACK* pstack) {

	if (pstack->top >= STACK_SIZE) {
		printf("STACK IS FULL!!\n");
		return true;
	}

	else
		return false;
}

void push(STACK* pstack, element value) {

	if (isFull(pstack)) {
		printf("STACK IS FULL!!\n");
		return;
	}

	else {

		pstack->top += 1;
		pstack->stack[pstack->top] = value;
		printf("stack[%d]�� %d�� �ԷµǾ����ϴ�.\n", pstack->top, pstack->stack[pstack->top]);
	}
}

element pop(STACK* pstack) {

	int temp;

	if (isEmpty(pstack)) {
		printf("STACK IS EMPTY!!\n");
		return 0;
	}

	else {

		temp = pstack->top;
		pstack->top -= 1;
		printf("stack[%d]�� %d�� ��µǾ����ϴ�.\n", temp, pstack->stack[temp]);
		return pstack->stack[temp];
	}
}

element peek(STACK* pstack) {

	if (isEmpty(pstack)) {
		printf("STACK IS EMPTY!!\n");
		exit(1);
	}

	else return pstack->stack[pstack->top];
}