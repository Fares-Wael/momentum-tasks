#include "list_interface.h"
#include <stdlib.h>

void CreateList(List *pl)
{
    pl->size = 0;
}

void InsertList(int p, ListEntry e, List *pl)
{
    for (int i = pl->size-1; i >= p; i--)
    {
        pl->entry[i+1] = pl->entry[i];
    }
    pl->entry[p] = e;
    pl->size++;
}

int ListkFull(List *pl)
{
    return pl->size == MAXLIST;
}

void DeleteList(int p, ListEntry *pe, List *pl)
{
        *pe = pl->entry[p];
        for (int i = p+1; i <= pl->size - 1; i++)
        {
            pl->entry[i-1] = pl->entry[i];
        }
        pl->size--;
}

int ListEmpty(List *pl)
{
    return !pl->size;
}

void RetrieveList(int p, ListEntry *pe, List *pl)
{

        *pe = pl->entry[p];
}

void ReplaceList(int p, ListEntry e, List *pl)
{
        pl->entry[p] = e;
}

int ListSize(List *pl)
{
    return pl->size;
}

void DestoryList(List *pl)
{
     pl->size = 0;
}

void TraverseList(List *pl, void (*Visit)(ListEntry))
{
    for (int i = 0; i < pl->size; i++)
    {
        (*Visit)(pl->entry[i]);
    }
}
