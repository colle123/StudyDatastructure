#include <stdio.h>
#include <string.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct _node
{
    char data;
    struct _node* next;
}Node;

typedef int LData;

typedef struct _linkedList
{
    Node* head;
    Node* cur;
    Node* tail;
}LinkedList;

typedef LinkedList List;

void ListInit(List* plist)
{

    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;

}

void CreatNode(List* plist, char adata)
{

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = adata;
    newNode->next = plist->head->next;
    plist->head->next = newNode;

}

void lineNode(List* plist)
{
    List* p;
    List* key;
    p = plist;

    while (p->head->next != NULL)
    {
        if (p->head->data > p->head->next->data)
        {
            key = p->head->next;
            p->head->next = p->head->next->next;
            key->head->next = plist;
            plist = p = key;
        }
        p = p->head->next;
    }
}

PrintNode(List* plist)
{
    Node* cur = plist->head->next;

    if (cur == NULL) printf("%c", cur->data);
    while (cur != NULL)
    {
        printf("%5c", cur->data);
        cur = cur->next;
    }
}

void Listadd(List* plist)
{
    char ata;

    while (1)
    {
        printf("단어를 입력하여 주세요\n탈출시 n입력\n");
        scanf("%c%*c", &ata);

        if (ata == 'n') break;
        else
            CreatNode(&plist, ata);

    }
}
int main()
{
    List list;
    ListInit(&list);
    int MeueNum;

    printf("(1)영어 입력\n (2)영어 전체 출력\n");
    scanf("%d", &MeueNum);

    while (1) {
        switch (MeueNum)      //   입력받은 값비교
        {
        case 1:            // 
        {
            Listadd(&list);
            break;;
        }
        case 2:
        {
            lineNode(&list);
            PrintNode(&list);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}