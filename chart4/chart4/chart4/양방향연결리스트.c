#include <stdio.h>

typedef struct dnode {

	int data;
	struct dnode* next;   // 뒤노드와 연결할 멤버
	struct dnode* prev;   // 앞노드를 연결할 멤버
}Dnode;

void insertNode(Dnode*, int, Dnode*, char); // 함수의 선언에서는 매개변수명을 쓰지 않아도 됨.
Dnode* searchNode(Dnode*, int);
void printNode(Dnode*);
void allDelNode(Dnode*);
void removeNode(Dnode*, Dnode*);

int main() {

	Dnode* head = (Dnode*)malloc(sizeof(Dnode));

	if (head == NULL) exit(1);
	head->next = NULL;
	head->prev = NULL;
	Dnode* pos = NULL;                                   // 기준노드, 검색노드의 주소를 저장

	
	insertNode(head, 10, pos, 'n');
	insertNode(head, 20, searchNode(head, 10), 'n');
	insertNode(head, 30, searchNode(head, 20), 'p');
	insertNode(head, 40, searchNode(head, 30), 'n');
	insertNode(head, 50, searchNode(head, 40), 'p');
	insertNode(head, 60, searchNode(head, 50), 'n');
	insertNode(head, 70, searchNode(head, 60), 'p');
	insertNode(head, 80, searchNode(head, 70), 'n');
	insertNode(head, 90, searchNode(head, 80), 'p');

	printf("==== 삭제 전 ====\n");
	printNode(head);

	allDelNode(head);
	//removeNode(head, searchNode(head, 10));
	//insertNode(head, 10, searchNode(head, 30), 'p');
	//removeNode(head, searchNode(head, 20));
	//insertNode(head, 20, searchNode(head, 40), 'n');

	printf("==== 삭제 후 ====\n");
	//printNode(head);

	return 0;
}

void insertNode(Dnode* h, int d, Dnode* p, char opt) {

	// 노드생성 및 초기화
	Dnode* newNode = (Dnode*)malloc(sizeof(Dnode));

	if (newNode == NULL) return; // 역참조 방지
	newNode->data = d;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (p == NULL) {                                     // 첫번째 노드를 삽입
		newNode->next = h->next;
		if (h->next != NULL) {                           // 기존의 노드가 만들어져 있는 경우
			newNode->next->prev = newNode;
		}
		h->next = newNode;
	}
	else {                                               // 원하는 위치로 삽입

		Dnode* curr = h->next;
		while (curr != p) {
			curr = curr->next;
		}

		if (opt == 'p') {                                // 전위 삽입

			newNode->prev = curr->prev;
			curr->prev = newNode;
			newNode->next = curr;
			newNode->prev->next = newNode;
			
		}

		else if (opt == 'n') {                           // 후위 삽입

			newNode->next = curr->next;
			curr->next = newNode;
			newNode->prev = curr;
			if(newNode->next !=NULL)
				newNode->next->prev = newNode;

		}
	
	}
}

Dnode* searchNode(Dnode* h, int d) {                                   // 대충 curr이 head 다음 노드부터 마지막노드까지 순회하며 입력된 d값과 일치되는 노드를 찾고 그 노드를 반환하는 함수

	Dnode* curr = h->next;

	while (curr != NULL) {

		if (curr->data == d)
			return curr;

		curr = curr->next;
	}

	
}

void printNode(Dnode* h) {                                             // 대충 curr이 head 다음 노드부터 마지막노드까지 순회하며 출력한다는 함수

	Dnode* curr = h->next;
		
	while (curr != NULL) {

		printf("%d\n", curr->data);

		curr = curr->next;
	}
	
}

void allDelNode(Dnode* h) {

	Dnode* curr = h->next;

	while (curr != NULL) {                                             // 마지막 노드가 될 때까지 반복함

		h->next = curr->next;
		free(curr);
		curr = h->next;                                                // head 다음에 있는 curr을 free() 해줬기 때문에 새롭게 head 다음에 있는 위치로 curr를 재정의해줌.
		 
	}

	free(h);                                                           // head도 동적할당 해줬기 때문에 free()를 해줌.
}

void removeNode(Dnode* h, Dnode* p) {

	Dnode* curr = h->next;
	Dnode* delNode = NULL;

	if (curr->data == p->data) {                                       // 첫번째 노드가 삭제해야할 노드일 때

		h->next = curr->next;
		curr->next->prev = h;
		free(curr);

	}

	else {                                                             // 두번째이후 노드가 삭제해야할 노드일 때

		while (curr->next != NULL) {                                   // 삭제하고 싶은 노드의(delNode) 이전 노드를 찾기 때문에 다음노드인 delNode가 NULL값이면 안됨.

			if (curr->next->data == p->data) {

				delNode = curr->next;
				curr->next = delNode->next;
				if(delNode->next !=NULL)                               // delNode가 마지막노드이면 prev가 작동을 안 하기 때문에 조건문으로 마지막 노드인걸 찾음.
					delNode->next->prev = curr;
				free(delNode);
				break;                                                 // 삭제하면 반복문 탈출.
			}

			curr = curr->next;
		}
	}

}