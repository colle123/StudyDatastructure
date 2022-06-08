// 단순 연결리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {

	int data;             // 데이터를 저장할 멤버 변수
	struct _node* next;   // 노드주소를 저장할 포인트 멤버 변수
}Node;

int main() {

	/*Node node1, node2;
	node1.data = 10;
	node1.next = NULL; // 널포인터 : 아무 값도 가지지 않음.

	node2.data = 20;
	node2.next = NULL;
	node1.next = &node2;

	printf("%d %p\n", node1.data, node1.next);
	printf("%d %p\n", node2.data, node2.next);
	printf("%p\n", &node2);*/

	Node* head = (Node*)malloc(sizeof(Node));
	
	head->next = NULL;

	Node* node1 = (Node*)malloc(sizeof(Node)); // node1을 동적할당

	if (node1 == NULL) return;
	node1->data = 10;
	node1->next = NULL;
	head->next = node1;
	printf("%p %p\n", head->next, node1);

	Node* node2 = (Node*)malloc(sizeof(Node));

	if (node2 == NULL) return;
	node2->data = 20;
	node2->next = NULL;
	node1->next = node2;

	Node* node3 = (Node*)malloc(sizeof(Node));

	if (node3 == NULL) return;
	node3->data = 30;
	node3->next = NULL;
	node2->next = node3;

	Node* node4 = (Node*)malloc(sizeof(Node));

	if (node4 == NULL) return;
	node4->data = 40;
	node4->next = NULL;
	node3->next = node4;

	Node* curr = head->next;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}

	//printf("%d %p\n", node1->data, node1->next);
	//printf("%d %p\n", node2->data, node2->next);
	//printf("%d %p\n", node3->data, node3->next);
	
	free(node4);
	free(node3);
	free(node2);
	free(node1);
	free(head);

	return 0;
}