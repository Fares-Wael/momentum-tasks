#ifndef STACK_H
#define STACK_H

#define MAXSTACK 100

typedef int StackEntry;

typedef struct stack {
    int top;
    StackEntry entry[MAXSTACK];
} Stack;

void CreateStack(Stack *ps);
void push(StackEntry e, Stack *ps);
int StackFull(Stack *ps);
void pop(StackEntry *pe, Stack *ps);
int StackEmpty(Stack *ps);
void StackTop(StackEntry *pe, Stack *ps);
int StackSize(Stack *ps);
void ClearStack(Stack *ps);
void TraverseStack(Stack *ps, void (*pf)(StackEntry));
void Display(StackEntry e);

#endif

