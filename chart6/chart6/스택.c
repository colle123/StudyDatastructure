#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 5

typedef int element;           // �����ڷ��� 


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

bool isEmpty() {               // ������ ������ִ��� Ȯ��

	if (top <= -1)
		return true;

	else
		return false;

}

bool isFull() {                // ������ ��ȭ���� Ȯ��

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

	else stack[++top] = value; // top�� �ʱⰪ�� -1�̹Ƿ� ���� ���� �����ڸ� �̿��ؼ� 0���� �ٲ��ְ� �ű⿡ value�� �־���.
}

element pop() {                // ���ÿ��� ���

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