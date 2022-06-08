/*
	Alphabet_sort.c
	created : 2022. 3. 3
	Author : 윤수한
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {                                // 문자를 저장할 Ary 구조체 선언

	char data;
	struct _node* next;

}Ary;

char InsertData() {

	char temp;                                        // 조건문을 돌리려고 문자를 임시저장하는 temp를 선언

	while (1) {

		printf("알파벳 입력 : ");
		scanf(" %c%*c", &temp);

		if (temp >= 'a' && temp <= 'z') {             // 소문자 입력 받으면 temp값을 리턴

			return temp;
		}

		else if (temp >= 'A' && temp <= 'Z') {        // 대문자 입력 받으면 temp값을 리턴

			return temp;
		}

		else if (temp == '0') {                       // 0 입력 받으면 널값을 반환해서 do~while문을 끝냄 -> 입력종료

			return NULL;
		}

		printf("문자가 아닙니다.\n");                   // 소문자, 대문자, 0을 제외한 입력은 문자가 아니라고 출력
	
	}
}

void createNode(Ary* low_h, Ary* upp_h, char d) { 

	Ary* newNode = (Ary*)malloc(sizeof(Ary));        // 새로운 노드 생성

	if (newNode == NULL) return;                     // 역참조 방지

	if (d >= 'a' && d <= 'z') {                      // 소문자면 Lower_ary에 저장, 정렬할거라 그냥 전위 삽입

		newNode->data = d;
		newNode->next = NULL;

		newNode->next = low_h->next;
		low_h->next = newNode;
	}

	else if (d >= 'A' && d <= 'Z') {                 // 대문자면 Upper_ary에 저장, 정렬할거라 그냥 전위 삽입

		newNode->data = d;
		newNode->next = NULL;

		newNode->next = upp_h->next;
		upp_h->next = newNode;
	}

}


void printNode(Ary* low_h, Ary* upp_h) {

	if (low_h->next == NULL) printf("\nLOWER은 비어있습니다."); // Lower_ary에 문자가 하나도 없으면 비어있다고 출력

	else {

		Ary* Low_curr = low_h->next;                         // 헤더 앞부터 NULL 전까지 순회하는 Low_curr 생성

		printf("\nLOWER : ");
		while (Low_curr != NULL) {                           // 헤더 앞부터 NULL 전까지 소문자 출력

			printf("%c ", Low_curr->data);
			Low_curr = Low_curr->next;
		}

	}
	printf("\n");

	if (upp_h->next == NULL) printf("UPPER은 비어있습니다.");  // Upper_ary에 문자가 하나도 없으면 비어있다고 출력

	else {

		Ary* Upp_curr = upp_h->next;                         // 헤더 앞부터 NULL 전까지 순회하는 Upp_curr 생성

		printf("UPPER : ");
		while (Upp_curr != NULL) {                           // 헤더 앞부터 NULL 전까지 대문자 출력

			printf("%c ", Upp_curr->data);
			Upp_curr = Upp_curr->next;
		}

	}

	printf("\n입력종료.\n");
}


Ary* insertionSort(Ary* h) {                                 // 전체 삽입 정렬


	Ary* curr = h->next;                                     // h->next부터 데이터 탐색하는 curr 노드 생성
	Ary* Temp;                                               // 정렬하기 위해 값을 저장해두는 임시공간 Temp 노드 생성
	
	while (curr->next != NULL) {

		if (curr->data > curr->next->data) {                 // 사전순으로 전해주기 위해서 값을 비교해서 값이 큰걸 뒤로 보냄(A가 가장 숫자가 적으므로)

			Temp = curr->next;                               // 뒤 노드을 앞으로 보내주기 위해서 Temp에 저장
			curr->next = curr->next->next;                   // 뒤 노드를 앞 으로 보내기 때문에(=삭제와 유사) 앞 노드를 뒤로 2번째 있는 노드와 연결
			Temp->next = h->next;                            // Temp 노드를 head 노드와 그 다음 노드 사이에 삽입. 뒤 노드와 연결시켜줌 

			h->next = Temp;                                  // head 노드와 그 다음 노드 사이에 삽입 된 Temp 노드를 head 노드와 연결        

			curr = h->next;                                  // curr 위치를 다시 head 노드 다음(이동된 Temp 노드)로 보내줌.

			continue;                                        // 정렬이 끝날때까지 while문을 돌려야하니 continue로 되돌아가줌.
		}

		curr = curr->next;                                   // curr->data > curr->next->data을 찾기위해 curr을 계속 이동.
	}

	return h;
}

void freeNode(Ary* h) {                                      // 동적할당으로 받아온 노드들 프로그램 종료 전에 free() 시켜주는 작업 

	Ary* curr = h->next;

	while (curr != NULL) {

		h->next = curr->next;
		free(curr);
		curr = h->next;

	}

	free(h);                                                 // 전체 생성 노드를 free 한 후 헤더노드를 free 시켜줌
}


int main() {

	Ary* Low_head = (Ary*)malloc(sizeof(Ary));               // Lower_Ary 헤더 선언
	if (Low_head != NULL) Low_head->next = NULL;             // 역참조 방지

	Ary* Upp_head = (Ary*)malloc(sizeof(Ary));               // Upper_Ary 헤더 선언
	if (Upp_head != NULL) Upp_head->next = NULL;             // 역참조 방지

	char Data;

	printf(" 0을 누르면 입력을 종료합니다.\n");

	do {

		Data = InsertData();
		createNode(Low_head, Upp_head, Data);

	} while (Data != NULL);                                  // NULL 값(0이 입력)이 올 때까지 반복문을 돌림

	Low_head = insertionSort(Low_head);                      // 소문자 정렬
	Upp_head = insertionSort(Upp_head);                      // 대문자 정렬

	printNode(Low_head, Upp_head);                           // 소문자, 대문자 출력
	
	freeNode(Low_head);                                      // 소문자 free()
	freeNode(Upp_head);                                      // 대문자 free()
	   
	return 0;
}