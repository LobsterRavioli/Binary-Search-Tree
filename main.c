#include<stdio.h>
#include"BST.h"
#include"item.h"
int isBtree(BST tree);
int isBstRecursive(BST tree);
int main()
{
    BST tree=newBST();
    int v[10]={30,11,41,12,51,1,14,15,70,43};
    for(int i=0;i<10;i++)
        tree=insert(tree,v[i]);


    printf("%d\n",isBstRecursive(tree));
}

int isBstRecursive(BST tree)
{
    if(isEmptyBST(tree))            //un albero vuoto è binario di ricerca
        return 1;

    if(isEmptyBST(figlioSx(tree))  &&  !isEmptyBST(figlioDx(tree)))     //caso in cui la radice ha solo il figlio dx
    {
        if(isMin(getItem(figlioDx(tree)),getItem(tree)))                //paragono gli item 
            return 0;                                                   //risposta
    }
    if(isEmptyBST(figlioDx(tree))  && !isEmptyBST(figlioSx(tree)))     //caso in cui la radice ha solo il figlio sx
    {
        if(isMin(getItem(tree),getItem(figlioSx(tree)))) 
           return 0;
    }  
    return isBstRecursive(figlioSx(tree)) && isBstRecursive(figlioDx(tree));    //passo ricorsivo
}

