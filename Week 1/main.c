#include "stack.h"
#include <stdio.h>
#include <string.h>

void InfixToPostfix(Stack *ps, StackEntry *pe);
int precedence(char symbol);

char infix[MAXSTACK];
char postfix[MAXSTACK];

int main() {
    printf("Enter the Infix Expression : ");
    gets(infix);
    Stack s;
    CreateStack(&s);
    StackEntry e;
    InfixToPostfix(&s, &e);
    printf("The Postfix Expression : %s\n", postfix);
    return 0;
}

void InfixToPostfix(Stack *ps, StackEntry *pe) {
    int j = 0;
    char symbol;
    StackEntry topSymbol;
Stack s;
    for (int i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        switch(symbol) {
            case '(' :
                push(symbol, ps);
                break;
             case ')' :
                    pop(pe ,ps);
                    while(*pe != '(')
                    {
                        postfix[j++] = *pe;
                        pop(pe,ps);
                    }
                break;
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' :
                 StackTop(pe, ps);
                    while(!StackEmpty(ps) && precedence(*pe) >= precedence(symbol))
                    {
                        pop(pe, ps);
                        postfix[j++] = *pe;
                        if(!StackEmpty(ps)) StackTop(pe, ps);
                    }
                    push(symbol, ps);
                    break;
            default :
                postfix[j++] = symbol;
        }
    }
    while (!StackEmpty(ps)) {
        pop(&postfix[j++], ps);
    }
    postfix[j] = '\0';
}

int precedence(char symbol) {
    switch(symbol) {
        case '^' :
            return 3;
        case '/' :
        case '*' :
            return 2;
        case '+' :
        case '-' :
            return 1;
        default :
            return 0;
    }
}
