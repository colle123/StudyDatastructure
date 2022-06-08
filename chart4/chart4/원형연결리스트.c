#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data;
	struct node* next;

}Node;

void insertFirstNode(Node**, int);
void insertLastNode(Node**, int);
void printNode(Node*);
void allDelNode(Node*);
Node* searchNode(Node*, int);
//void removeNode(Node*, int);

int main() {

	Node* tail = NULL;

	insertFirstNode(&tail, 10); // 10
	insertLastNode(&tail, 20); // 10 20
	insertFirstNode(&tail, 30); // 30 10 20
	insertLastNode(&tail, 40); // 30 10 20 40

	printf("== ���� �� ==\n");
	printNode(tail);
	printf("\n");

	//printf("%d", searchNode(tail, 20)->data);

	//removeNode(tail, searchNode(tail, 10));

	allDelNode(tail);

	//printf("== ���� �� ==\n");
	//printNode(tail);

	return 0;
}

void insertFirstNode(Node** t, int d) {  // tail�� �����Ҵ����� �����߱� ������ Node* t ���·� ������ �� ���簡 �Ͼ 
	                                     // main()�Լ��� tail�� ������ �� ��ġ�� ���� �����ͷ� �������� �ּҰ��� �޾ƿ�.

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->next = NULL;
	newNode->data = d;

	if (*t == NULL) {                    // ��尡 �ϳ��� ������
		*t = newNode;
		newNode->next = newNode;
	}
	else {                              // ������ ������� ������

		newNode->next = (*t)->next;
		(*t)->next = newNode;
	}

}

void insertLastNode(Node** t, int d) {   // tail�� �����Ҵ����� �����߱� ������ Node* t ���·� ������ �� ���簡 �Ͼ 
	                                     // main()�Լ��� tail�� ������ �� ��ġ�� ���� �����ͷ� �������� �ּҰ��� �޾ƿ�.

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->next = NULL;
	newNode->data = d;

	if (*t == NULL) {                    // ��尡 �ϳ��� ������
		*t = newNode;
		newNode->next = newNode;
	}
	else {                               // ������ ������� ������

		newNode->next = (*t)->next;
		(*t)->next = newNode;
		(*t) = newNode;                  // ����������̹Ƿ� tail�� ��ġ�� �ٲ������.
	}

}

void printNode(Node* t) {

	Node* curr = t;

	if (t == NULL) return;               // ��尡 �ϳ��� ������

	else {
		do {

			curr = curr->next;           // ó�������� ����ؾ��ϱ� ������ tail�� �ʱ�ȭ�� curr�� ��ĭ ������ �̵�������.
			printf("%d ", curr->data);   // curr->data�� ���.
			
		} while (curr != t);             // curr�� tail�� �����ϸ� ��� ����.
	}
}

void allDelNode(Node* t) {

	Node* curr = t->next;                // curr�� t->next�� �����ؼ� ���� ù ��带 ����Ű�� ��. 
	Node* temp;                          // t->next�� ������ ��������Ŷ� curr�� tail�� ���� �޾ƿ��� ���ϴ� �ӽ����� �� temp ����.

	t->next = NULL;

	while (curr != t) {                  // t(������ ���)������ �ݺ����� ����

		temp = curr->next;               // curr�� free()���Ѿ� �ϴϱ� curr->next�� temp�� ������ѵ�.
		free(curr);                      // free(curr)�� �̿��� curr ����
		curr = temp;                     // temp = curr->next�̹Ƿ� ���� �� curr�� ���� ���� curr�� ������ ��.
	}

	free(t);                             // ������ ����� tail�� free()���Ѽ� ��������.

	printf("\nallDelNode() - ��带 ��� �������׽��ϴ�.\n");

}

Node* searchNode(Node* t, int d) {

	Node* curr = t;

	if (t == NULL) return;

	else {
		do {

			curr = curr->next;

			if (curr->data == d) {

				return curr;

			}
		} while (curr != t);
	}

	return NULL;
}

//void removeNode(Node* t, Node* p) {

//}