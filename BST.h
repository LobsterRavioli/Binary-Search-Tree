typedef struct node *BST;
#include"item.h"

BST newBST(void);
BST makeLeaf(item el);
int isEmptyBST(BST tree);
BST figlioDx(BST tree);
BST figlioSx(BST tree);
BST insert(BST tree,item el);
int contains(BST tree,item el);
BST deleteNode(BST tree,item el);
void PrintBst(BST tree);
int getItem(BST tree);
int isBstRecursive(BST tree);


