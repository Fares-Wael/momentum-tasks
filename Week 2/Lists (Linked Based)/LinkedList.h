#ifndef LinkedList_H
#define LinkedList_H

typedef int ListEntry;

typedef struct listnode
{
    ListEntry entry;
    struct listnode *next;
} ListNode;

typedef struct list
{
    int size;
    ListNode *head;
} List;

void CreateList(List *pl);
void InsertList(int p, ListEntry e, List *pl);
int ListkFull(List *pl);
void DeleteList(int p, ListEntry *pe, List *pl);
int ListEmpty(List *pl);
void RetrieveList(int p, ListEntry *pe, List *pl);
void ReplaceList(int p, ListEntry e, List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void TraverseList(List *ps, void (*Visit)(ListEntry));

#endif
