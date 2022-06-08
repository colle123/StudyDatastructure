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

	printf("== 삭제 전 ==\n");
	printNode(tail);
	printf("\n");

	//printf("%d", searchNode(tail, 20)->data);

	//removeNode(tail, searchNode(tail, 10));

	allDelNode(tail);

	//printf("== 삭제 후 ==\n");
	//printNode(tail);

	return 0;
}

void insertFirstNode(Node** t, int d) {  // tail을 정적할당으로 선언했기 때문에 Node* t 형태로 받으면 값 복사가 일어나 
	                                     // main()함수의 tail에 영향을 못 미치니 이중 포인터로 포인터의 주소값을 받아옴.

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->next = NULL;
	newNode->data = d;

	if (*t == NULL) {                    // 노드가 하나도 없을때
		*t = newNode;
		newNode->next = newNode;
	}
	else {                              // 노드들이 만들어져 있을때

		newNode->next = (*t)->next;
		(*t)->next = newNode;
	}

}

void insertLastNode(Node** t, int d) {   // tail을 정적할당으로 선언했기 때문에 Node* t 형태로 받으면 값 복사가 일어나 
	                                     // main()함수의 tail에 영향을 못 미치니 이중 포인터로 포인터의 주소값을 받아옴.

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->next = NULL;
	newNode->data = d;

	if (*t == NULL) {                    // 노드가 하나도 없을때
		*t = newNode;
		newNode->next = newNode;
	}
	else {                               // 노드들이 만들어져 있을때

		newNode->next = (*t)->next;
		(*t)->next = newNode;
		(*t) = newNode;                  // 마지막노드이므로 tail의 위치를 바꿔줘야함.
	}

}

void printNode(Node* t) {

	Node* curr = t;

	if (t == NULL) return;               // 노드가 하나도 없을때

	else {
		do {

			curr = curr->next;           // 처음노드부터 출력해야하기 때문에 tail로 초기화한 curr을 한칸 앞으로 이동시켜줌.
			printf("%d ", curr->data);   // curr->data를 출력.
			
		} while (curr != t);             // curr이 tail에 도착하면 출력 중지.
	}
}

void allDelNode(Node* t) {

	Node* curr = t->next;                // curr을 t->next로 설정해서 가장 첫 노드를 가리키게 함. 
	Node* temp;                          // t->next의 연결을 끊어버릴거라 curr이 tail의 값을 받아오지 못하니 임시저장 할 temp 선언.

	t->next = NULL;

	while (curr != t) {                  // t(마지막 노드)전까지 반복문을 돌림

		temp = curr->next;               // curr을 free()시켜야 하니깐 curr->next를 temp에 저장시켜둠.
		free(curr);                      // free(curr)을 이용해 curr 삭제
		curr = temp;                     // temp = curr->next이므로 삭제 된 curr의 다음 노드로 curr을 재정의 함.
	}

	free(t);                             // 마지막 노드인 tail를 free()시켜서 삭제해줌.

	printf("\nallDelNode() - 노드를 모두 삭제시켰습니다.\n");

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