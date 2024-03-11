#ifndef list_interface_H
#define list_interface_H

#define MAXLIST 100

typedef int ListEntry;

typedef struct list {
    int size;
    ListEntry entry[MAXLIST];
} List;

void CreateList(List *pl);
void InsertList(int p ,ListEntry e, List *pl);
int ListkFull(List *pl);
void DeleteList(int p ,ListEntry *pe, List *pl);
int ListEmpty(List *pl);
void RetrieveList(int p ,ListEntry *pe, List *pl);
void ReplaceList(int p ,ListEntry e, List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void TraverseList(List *ps, void (*Visit)(ListEntry));

#endif
