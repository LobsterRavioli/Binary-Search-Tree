#include<stdio.h>

#include"item.h"

int eq(item x,item y)
{
	return x == y;
}

int isMin(item n1,item n2)
{
    return n1 < n2;

}

void inputItem(item *x)
{
	scanf("%d",x);
}
void outputItem(item x)
{
	printf("%d ",x);
}

void copyItem(item x)
{
}

void creItem(int memb1)
{
}

int extractMemb1(item x)
{
}

int extractMemb2(item x)
{
}

void deleteItem(item x)
{
}