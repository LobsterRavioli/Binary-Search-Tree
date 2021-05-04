#include<stdio.h>
#include<stdlib.h>

#include"item.h"
#include"BST.h"

typedef struct node
{
    struct node *left;
    struct node *right;
    item el;

}node;

BST newBST(void)
{
    return NULL;
}

BST makeLeaf(item el)
{
    BST leaf=malloc(sizeof(node));
    leaf->el=el;
    leaf->right=NULL;
    leaf->left=NULL;
    return leaf;
}
item getItem(BST tree)
{
    return tree->el;
}

int isEmptyBST(BST tree)
{
    return !tree;
}

BST figlioDx(BST tree)
{
    if(tree)
        return tree->right;

    return tree;
}
BST figlioSx(BST tree)
{
     if(tree)
        return tree->left;

    return tree;
}
BST insert(BST tree,item el)
{
    if(!tree)
        return makeLeaf(el);

    if(isMin(el,getItem(tree)))
        tree->left=insert(tree->left,el);

    if(isMin(getItem(tree),el))
        tree->right=insert(tree->right,el);

    return tree;
}
/*
int isBstRecursive(BST tree)
{
    if(!tree)
        return 1;

    if(!tree->left && !isEmptyBST(tree->right))
    {
        if(getItem(tree) > getItem(tree->right))
            return 0;
    }
    if(!tree->right && !isEmptyBST(tree->left))
    {
        if(getItem(tree) < getItem(tree->left))
           return 0;
    }
    if((!isEmptyBST(tree->right)) && !isEmptyBST(tree->left))
        return isBstRecursive(tree->left) && isBstRecursive(tree->right);
}
*/
int contains(BST tree,item el)
{
    if(!tree)
        return 0;

    if(eq(el,getItem(tree)))
        return 1;

    if(isMin(el,getItem(tree)))
        return contains(tree->left,el);
    else
        return contains(tree->right,el);
}



static node *MinTree(node *root)
{
    node *current=root;

    while(current->left != NULL)
        current=MinTree(current->left);

    return current;
}

BST deleteNode(BST tree,item el)
{
    if(!tree)
        return tree;

    if(isMin(el,getItem(tree)))
        tree->left=insert(tree->left,el);

    if(isMin(getItem(tree),el))
        tree->right=insert(tree->right,el);

    else
    {
        if(tree->left == NULL)
        {
            node *temp=tree->right;
            free(tree);
            return temp;
        }

        else if(tree->right == NULL)
        {
            node *temp=tree->right;
            free(tree);
            return temp;
        }

        node *temp=MinTree(tree->right);
        tree->el=temp->el;
        tree=deleteNode(tree->right,temp->el);
    }

    return tree;
}

void preOrder(BST tree)
{
    if(isEmptyBST(tree))
        return;
    outputItem(getItem(tree));
    preOrder(figlioSx(tree));
    preOrder(figlioDx(tree));
}

void postOrder(BST tree)
{
    if(isEmptyBST(tree))
        return;
    postOrder(figlioSx(tree));
    postOrder(figlioDx(tree));
    outputItem(getItem(tree));
}
void inOrder(BST tree)
{
    if(isEmptyBST(tree))
        return;
    inOrder(figlioSx(tree));
    outputItem(getItem(tree));
    inOrder(figlioDx(tree));
}

void PrintBst(BST tree)
{
    printf("Pre-order:");
    preOrder(tree);
    printf("\n");
    printf("Post-order:");
    postOrder(tree);
    printf("\n");
    printf("In-order:");
    inOrder(tree);
    printf("\n");
}

