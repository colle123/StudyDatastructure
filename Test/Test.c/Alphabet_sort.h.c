/*
	Alphabet_sort.c
	created : 2022. 3. 3
	Author : ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {                                // ���ڸ� ������ Ary ����ü ����

	char data;
	struct _node* next;

}Ary;

char InsertData() {

	char temp;                                        // ���ǹ��� �������� ���ڸ� �ӽ������ϴ� temp�� ����

	while (1) {

		printf("���ĺ� �Է� : ");
		scanf(" %c%*c", &temp);

		if (temp >= 'a' && temp <= 'z') {             // �ҹ��� �Է� ������ temp���� ����

			return temp;
		}

		else if (temp >= 'A' && temp <= 'Z') {        // �빮�� �Է� ������ temp���� ����

			return temp;
		}

		else if (temp == '0') {                       // 0 �Է� ������ �ΰ��� ��ȯ�ؼ� do~while���� ���� -> �Է�����

			return NULL;
		}

		printf("���ڰ� �ƴմϴ�.\n");                   // �ҹ���, �빮��, 0�� ������ �Է��� ���ڰ� �ƴ϶�� ���
	
	}
}

void createNode(Ary* low_h, Ary* upp_h, char d) { 

	Ary* newNode = (Ary*)malloc(sizeof(Ary));        // ���ο� ��� ����

	if (newNode == NULL) return;                     // ������ ����

	if (d >= 'a' && d <= 'z') {                      // �ҹ��ڸ� Lower_ary�� ����, �����ҰŶ� �׳� ���� ����

		newNode->data = d;
		newNode->next = NULL;

		newNode->next = low_h->next;
		low_h->next = newNode;
	}

	else if (d >= 'A' && d <= 'Z') {                 // �빮�ڸ� Upper_ary�� ����, �����ҰŶ� �׳� ���� ����

		newNode->data = d;
		newNode->next = NULL;

		newNode->next = upp_h->next;
		upp_h->next = newNode;
	}

}


void printNode(Ary* low_h, Ary* upp_h) {

	if (low_h->next == NULL) printf("\nLOWER�� ����ֽ��ϴ�."); // Lower_ary�� ���ڰ� �ϳ��� ������ ����ִٰ� ���

	else {

		Ary* Low_curr = low_h->next;                         // ��� �պ��� NULL ������ ��ȸ�ϴ� Low_curr ����

		printf("\nLOWER : ");
		while (Low_curr != NULL) {                           // ��� �պ��� NULL ������ �ҹ��� ���

			printf("%c ", Low_curr->data);
			Low_curr = Low_curr->next;
		}

	}
	printf("\n");

	if (upp_h->next == NULL) printf("UPPER�� ����ֽ��ϴ�.");  // Upper_ary�� ���ڰ� �ϳ��� ������ ����ִٰ� ���

	else {

		Ary* Upp_curr = upp_h->next;                         // ��� �պ��� NULL ������ ��ȸ�ϴ� Upp_curr ����

		printf("UPPER : ");
		while (Upp_curr != NULL) {                           // ��� �պ��� NULL ������ �빮�� ���

			printf("%c ", Upp_curr->data);
			Upp_curr = Upp_curr->next;
		}

	}

	printf("\n�Է�����.\n");
}


Ary* insertionSort(Ary* h) {                                 // ��ü ���� ����


	Ary* curr = h->next;                                     // h->next���� ������ Ž���ϴ� curr ��� ����
	Ary* Temp;                                               // �����ϱ� ���� ���� �����صδ� �ӽð��� Temp ��� ����
	
	while (curr->next != NULL) {

		if (curr->data > curr->next->data) {                 // ���������� �����ֱ� ���ؼ� ���� ���ؼ� ���� ū�� �ڷ� ����(A�� ���� ���ڰ� �����Ƿ�)

			Temp = curr->next;                               // �� ����� ������ �����ֱ� ���ؼ� Temp�� ����
			curr->next = curr->next->next;                   // �� ��带 �� ���� ������ ������(=������ ����) �� ��带 �ڷ� 2��° �ִ� ���� ����
			Temp->next = h->next;                            // Temp ��带 head ���� �� ���� ��� ���̿� ����. �� ���� ��������� 

			h->next = Temp;                                  // head ���� �� ���� ��� ���̿� ���� �� Temp ��带 head ���� ����        

			curr = h->next;                                  // curr ��ġ�� �ٽ� head ��� ����(�̵��� Temp ���)�� ������.

			continue;                                        // ������ ���������� while���� �������ϴ� continue�� �ǵ��ư���.
		}

		curr = curr->next;                                   // curr->data > curr->next->data�� ã������ curr�� ��� �̵�.
	}

	return h;
}

void freeNode(Ary* h) {                                      // �����Ҵ����� �޾ƿ� ���� ���α׷� ���� ���� free() �����ִ� �۾� 

	Ary* curr = h->next;

	while (curr != NULL) {

		h->next = curr->next;
		free(curr);
		curr = h->next;

	}

	free(h);                                                 // ��ü ���� ��带 free �� �� �����带 free ������
}


int main() {

	Ary* Low_head = (Ary*)malloc(sizeof(Ary));               // Lower_Ary ��� ����
	if (Low_head != NULL) Low_head->next = NULL;             // ������ ����

	Ary* Upp_head = (Ary*)malloc(sizeof(Ary));               // Upper_Ary ��� ����
	if (Upp_head != NULL) Upp_head->next = NULL;             // ������ ����

	char Data;

	printf(" 0�� ������ �Է��� �����մϴ�.\n");

	do {

		Data = InsertData();
		createNode(Low_head, Upp_head, Data);

	} while (Data != NULL);                                  // NULL ��(0�� �Է�)�� �� ������ �ݺ����� ����

	Low_head = insertionSort(Low_head);                      // �ҹ��� ����
	Upp_head = insertionSort(Upp_head);                      // �빮�� ����

	printNode(Low_head, Upp_head);                           // �ҹ���, �빮�� ���
	
	freeNode(Low_head);                                      // �ҹ��� free()
	freeNode(Upp_head);                                      // �빮�� free()
	   
	return 0;
}