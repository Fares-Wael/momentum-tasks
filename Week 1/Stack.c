#include "stack.h"

void CreateStack(Stack *ps) {
    ps->top = 0;
}

void push(StackEntry e, Stack *ps) {
    ps->entry[ps->top++] = e;
}

int StackFull(Stack *ps) {
    return ps->top == MAXSTACK;
}

void pop(StackEntry *pe, Stack *ps) {
    *pe = ps->entry[--ps->top];
}

int StackEmpty(Stack *ps) {
    return ps->top == 0;
}

void StackTop(StackEntry *pe, Stack *ps) {
    if (!StackEmpty(ps)) {
        *pe = ps->entry[ps->top - 1];
    }
}

int StackSize(Stack *ps) {
    return ps->top;
}

void ClearStack(Stack *ps) {
    ps->top = 0;
}

void TraverseStack(Stack *ps, void (*pf)(StackEntry)) {
    for (int i = ps->top; i > 0; i--)
        (*pf)(ps->entry[i - 1]);
}

void Display(StackEntry e) {
    if (e == '+' || e == '-' || e == '*' || e == '/')
        printf("%c ", e);
    else
        printf("%d ", e);
}

