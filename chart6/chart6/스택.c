#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 5

typedef int element;           // 스택자료형 


bool isEmpty();
bool isFull();
void push(element);
element pop();
element peek();

element stack[STACK_SIZE];
int top = -1;

int main() {



	return 0;
}

bool isEmpty() {               // 스택이 비워져있는지 확인

	if (top <= -1)
		return true;

	else
		return false;

}

bool isFull() {                // 스택의 포화상태 확인

	if (top >= STACK_SIZE - 1)
		return true;

	else
		return false;

}

void push(element value) {

	if (isFull()) {

		printf("STACK IS FULL!!\n");
		return;
	}

	else stack[++top] = value; // top의 초기값이 -1이므로 전위 증가 연산자를 이용해서 0으로 바꿔주고 거기에 value를 넣어줌.
}

element pop() {                // 스택원소 출력

	if (isEmpty()) {

		printf("STACK IS EMPTY!!\n");
		return 0;
	}

	else return stack[top--];
}

element peek() {

	if (isEmpty()) {

		printf("STACK IS EMPTY !!\n");
		exit(1);
	}

	else return stack[top];
}