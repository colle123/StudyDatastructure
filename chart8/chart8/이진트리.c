#include <stdio.h>
#include <stdlib.h>


typedef struct tnode {

	char ch;
	struct tnode* left;
	struct tnode* right;

}TNode;

TNode* createNode(char ach) {

	TNode* newNode = (TNode*)malloc(sizeof(TNode));

	if (newNode == NULL) return;

	newNode->ch = ach;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

makeTreeNode(TNode* aroot, TNode* al, TNode* ar) {

	aroot->left = al;
	aroot->right = ar;

}


int main() {

	TNode* t1 = createNode('a');
	TNode* t2 = createNode('b');
	TNode* t3 = createNode('c');
	TNode* t4 = createNode('c');
	TNode* t5 = createNode('c');
	TNode* t6 = createNode('c');
	TNode* t7 = createNode('c');
	TNode* t8 = createNode('c');
	TNode* t9 = createNode('c'); 

	printf("%c %c %c\n", t1->ch, t2->ch, t3->ch);

	makeTreeNode(t1, t2, t3);
	makeTreeNode(t2, t4, t5);
	makeTreeNode(t3, t6, t7);
	makeTreeNode(t4, t8, NULL);
	makeTreeNode(t5, NULL, t9);

	printf("%c %c %c\n", t1->ch, t1->left->ch, t1->right->ch);


	return 0;
}