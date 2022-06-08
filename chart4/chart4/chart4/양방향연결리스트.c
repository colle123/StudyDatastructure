#include <stdio.h>

typedef struct dnode {

	int data;
	struct dnode* next;   // �ڳ��� ������ ���
	struct dnode* prev;   // �ճ�带 ������ ���
}Dnode;

void insertNode(Dnode*, int, Dnode*, char); // �Լ��� ���𿡼��� �Ű��������� ���� �ʾƵ� ��.
Dnode* searchNode(Dnode*, int);
void printNode(Dnode*);
void allDelNode(Dnode*);
void removeNode(Dnode*, Dnode*);

int main() {

	Dnode* head = (Dnode*)malloc(sizeof(Dnode));

	if (head == NULL) exit(1);
	head->next = NULL;
	head->prev = NULL;
	Dnode* pos = NULL;                                   // ���س��, �˻������ �ּҸ� ����

	
	insertNode(head, 10, pos, 'n');
	insertNode(head, 20, searchNode(head, 10), 'n');
	insertNode(head, 30, searchNode(head, 20), 'p');
	insertNode(head, 40, searchNode(head, 30), 'n');
	insertNode(head, 50, searchNode(head, 40), 'p');
	insertNode(head, 60, searchNode(head, 50), 'n');
	insertNode(head, 70, searchNode(head, 60), 'p');
	insertNode(head, 80, searchNode(head, 70), 'n');
	insertNode(head, 90, searchNode(head, 80), 'p');

	printf("==== ���� �� ====\n");
	printNode(head);

	allDelNode(head);
	//removeNode(head, searchNode(head, 10));
	//insertNode(head, 10, searchNode(head, 30), 'p');
	//removeNode(head, searchNode(head, 20));
	//insertNode(head, 20, searchNode(head, 40), 'n');

	printf("==== ���� �� ====\n");
	//printNode(head);

	return 0;
}

void insertNode(Dnode* h, int d, Dnode* p, char opt) {

	// ������ �� �ʱ�ȭ
	Dnode* newNode = (Dnode*)malloc(sizeof(Dnode));

	if (newNode == NULL) return; // ������ ����
	newNode->data = d;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (p == NULL) {                                     // ù��° ��带 ����
		newNode->next = h->next;
		if (h->next != NULL) {                           // ������ ��尡 ������� �ִ� ���
			newNode->next->prev = newNode;
		}
		h->next = newNode;
	}
	else {                                               // ���ϴ� ��ġ�� ����

		Dnode* curr = h->next;
		while (curr != p) {
			curr = curr->next;
		}

		if (opt == 'p') {                                // ���� ����

			newNode->prev = curr->prev;
			curr->prev = newNode;
			newNode->next = curr;
			newNode->prev->next = newNode;
			
		}

		else if (opt == 'n') {                           // ���� ����

			newNode->next = curr->next;
			curr->next = newNode;
			newNode->prev = curr;
			if(newNode->next !=NULL)
				newNode->next->prev = newNode;

		}
	
	}
}

Dnode* searchNode(Dnode* h, int d) {                                   // ���� curr�� head ���� ������ ������������ ��ȸ�ϸ� �Էµ� d���� ��ġ�Ǵ� ��带 ã�� �� ��带 ��ȯ�ϴ� �Լ�

	Dnode* curr = h->next;

	while (curr != NULL) {

		if (curr->data == d)
			return curr;

		curr = curr->next;
	}

	
}

void printNode(Dnode* h) {                                             // ���� curr�� head ���� ������ ������������ ��ȸ�ϸ� ����Ѵٴ� �Լ�

	Dnode* curr = h->next;
		
	while (curr != NULL) {

		printf("%d\n", curr->data);

		curr = curr->next;
	}
	
}

void allDelNode(Dnode* h) {

	Dnode* curr = h->next;

	while (curr != NULL) {                                             // ������ ��尡 �� ������ �ݺ���

		h->next = curr->next;
		free(curr);
		curr = h->next;                                                // head ������ �ִ� curr�� free() ����� ������ ���Ӱ� head ������ �ִ� ��ġ�� curr�� ����������.
		 
	}

	free(h);                                                           // head�� �����Ҵ� ����� ������ free()�� ����.
}

void removeNode(Dnode* h, Dnode* p) {

	Dnode* curr = h->next;
	Dnode* delNode = NULL;

	if (curr->data == p->data) {                                       // ù��° ��尡 �����ؾ��� ����� ��

		h->next = curr->next;
		curr->next->prev = h;
		free(curr);

	}

	else {                                                             // �ι�°���� ��尡 �����ؾ��� ����� ��

		while (curr->next != NULL) {                                   // �����ϰ� ���� �����(delNode) ���� ��带 ã�� ������ ��������� delNode�� NULL���̸� �ȵ�.

			if (curr->next->data == p->data) {

				delNode = curr->next;
				curr->next = delNode->next;
				if(delNode->next !=NULL)                               // delNode�� ����������̸� prev�� �۵��� �� �ϱ� ������ ���ǹ����� ������ ����ΰ� ã��.
					delNode->next->prev = curr;
				free(delNode);
				break;                                                 // �����ϸ� �ݺ��� Ż��.
			}

			curr = curr->next;
		}
	}

}