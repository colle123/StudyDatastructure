/* 순차리스트 배열구현 */

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

	printf("========== 입력 ==========\n\n");

	push(&S, 10);                 // stack[0]에 10이 입력되고 top이 0이 됨  현재 10
	push(&S, 20);                 // stack[1]에 20이 입력되고 top이 1이 됨  현재 10 20
	push(&S, 30);                 // stack[2]에 30이 입력되고 top이 2가 됨  현재 10 20 30

	printf("\n========== 출력 ==========\n\n");
	pop(&S);                      // stack[2]에 있던 30이 출력되고 top이 1이됨 현재 10 20
	pop(&S);                      // stack[1]에 있던 20이 출력되고 top이 0이됨 현재 10
	pop(&S);                      // stack[0]에 있던 10이 출력되고 top이 -1이됨 현재 empty

	return 0;
}

void initSTACK(STACK* pstack) {   // stack의 top을 -1로 초기화시켜서 비어있는 상태로 만들어버림

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
		printf("stack[%d]에 %d가 입력되었습니다.\n", pstack->top, pstack->stack[pstack->top]);
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
		printf("stack[%d]에 %d가 출력되었습니다.\n", temp, pstack->stack[temp]);
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