#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Stack structure for characters
struct stack {
    int top;
    int size;
    char *arr;
};

// Stack structure for integers (used during postfix evaluation)
struct intStack {
    int top;
    int size;
    int *arr;
};

// Stack functions for characters
void initStack(struct stack *s, int size) {
    s->size = size;
    s->top = -1;
    s->arr = (char *)malloc(size * sizeof(char));
}

int isEmpty(struct stack *s) {
    return s->top == -1;
}

int isFull(struct stack *s) {
    return s->top == s->size - 1;
}

void push(struct stack *s, char val) {
    if (isFull(s)) return;
    s->arr[++s->top] = val;
}

char pop(struct stack *s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top--];
}

char peek(struct stack *s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top];
}

// Stack functions for integers
void initIntStack(struct intStack *s, int size) {
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(size * sizeof(int));
}

int isIntEmpty(struct intStack *s) {
    return s->top == -1;
}

void pushInt(struct intStack *s, int val) {
    s->arr[++s->top] = val;
}

int popInt(struct intStack *s) {
    if (isIntEmpty(s)) return -1;
    return s->arr[s->top--];
}

// Utility functions
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

// Convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    struct stack s;
    initStack(&s, strlen(infix));
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isdigit(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s); // remove '('
        } else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c))
                postfix[j++] = pop(&s);
            push(&s, c);
        }
    }

    while (!isEmpty(&s))
        postfix[j++] = pop(&s);

    postfix[j] = '\0';
    free(s.arr);
}

// Evaluate postfix expression
int evaluatePostfix(char *postfix) {
    struct intStack s;
    initIntStack(&s, strlen(postfix));

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            pushInt(&s, c - '0');
        } else if (isOperator(c)) {
            int val2 = popInt(&s);
            int val1 = popInt(&s);
            int result = 0;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '%': result = val1 % val2; break;
                case '^': result = pow(val1, val2); break;
            }
            pushInt(&s, result);
        }
    }

    int res = popInt(&s);
    free(s.arr);
    return res;
}

// Main function
int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression (single-digit numbers): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated result: %d\n", result);

    return 0;
}
