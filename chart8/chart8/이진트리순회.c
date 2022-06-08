#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct tnode {

	element data;
	struct tnode* left;
	struct tnode* right;

}TNode;

TNode* createNode(char Tdata) {

	TNode* newNode = (TNode*)malloc(sizeof(TNode));

	if (newNode == NULL) return;

	newNode->data = Tdata;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

makeTreeNode(TNode* aroot, TNode* Tleft, TNode* Tright) {

	aroot->left = Tleft;
	aroot->right = Tright;

}

void PreorderTree(TNode* aroot) {                        // 전위순회

	if (aroot == NULL) return;                    // 조건이 없으면 무한루프하기 때문에 조건을 넣어줌. 

	printf("%c ", aroot->data);
	PreorderTree(aroot->left);
	PreorderTree(aroot->right);

}

void InorderTree(TNode* aroot) {                         // 중위순회

	if (aroot == NULL) return;

	InorderTree(aroot->left);
	printf("%c ", aroot->data);
	InorderTree(aroot->right);

}

void PostorderTree(TNode* aroot) {                       // 후위순회

	if (aroot == NULL) return;

	PostorderTree(aroot->left);
	PostorderTree(aroot->right);
	printf("%c ", aroot->data);
	
}

int main() {

	TNode* t1 = createNode('가나');
	TNode* t2 = createNode('B');
	TNode* t3 = createNode('C');
	TNode* t4 = createNode('D');
	TNode* t5 = createNode('E');
	TNode* t6 = createNode('F');
	TNode* t7 = createNode('G');
	TNode* t8 = createNode('H');
	TNode* t9 = createNode('I');


	makeTreeNode(t1, t2, t3);
	makeTreeNode(t2, t4, t5);
	makeTreeNode(t3, t6, t7);
	makeTreeNode(t4, t8, NULL);
	makeTreeNode(t5, NULL, t9);

	PreorderTree(t1);
	printf("\n");
	InorderTree(t1);
	printf("\n");
	PostorderTree(t1);
	printf("\n");


	return 0;
}
