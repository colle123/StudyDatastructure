#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

typedef char element;

typedef struct {
	element que[SIZE];            // 큐배열
	int front, rear;              // 위치멤버, front(출구), rear(입구)
}QUEUE;

QUEUE* createQ() {

	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
	if (q == NULL) exit(1);

	q->rear = -1;
	q->front = -1;

	return q;
}

bool isEmpty(QUEUE* apq) {

	if (apq->front == apq->rear) {

		printf("QUEUE IS EMPTY!!\n");
		return true;
	}

	else return false;
}

bool isFull(QUEUE* apq) {

	if (apq->rear >= SIZE - 1) {

		printf("QUEUE IS FULL!!\n");
		return true;
	}

	else return false;
}

void enQueue(QUEUE* apq, element adata) {

	if (isFull(apq)) return;

	apq->que[++(apq->rear)] = adata;

}

element deQueue(QUEUE* apq) {

	if (isEmpty(apq)) return '\0';

	return apq->que[++(apq->front)];

}

element peek(QUEUE* apq) {

	if (isEmpty(apq)) return '\0';

	return apq->que[apq->rear];

}

element printQueue(QUEUE* apq) {

	if (isEmpty(apq)) return '\0';

	for (int i = apq->front + 1; i <= apq->rear; i++) {

		printf("%c ", apq->que[i]);
	}

	//while (apq->front < apq->rear) {

	//	apq->front += 1;
	//	printf("%c ", apq->que[apq->front]);
	//	
	//}

	//do {
	//	
	//	apq->front += 1;
	//	printf("%c ", apq->que[apq->front]);

	//} while (apq->front < apq->rear);
}

int main() {

	QUEUE* Q = createQ();

	enQueue(Q, 'A');
	enQueue(Q, 'B');
	enQueue(Q, 'C');
	enQueue(Q, 'D');

	printQueue(Q);

	return 0;
}
