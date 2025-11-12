#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct stack {
    int top;
    int size;
    char *arr;
};

struct intStack {
    int top;
    int size;
    int *arr;
};

// Stack functions for characters
int isEmpty(struct stack *s) { return (s->top == -1); }
int isFull(struct stack *s) { return (s->top == s->size - 1); }

void push(struct stack *s, char data) {
    if (isFull(s))
        printf("Stack Overflow\n");
    else
        s->arr[++s->top] = data;
}

char pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Stack functions for integers
int isIntEmpty(struct intStack *s) { return (s->top == -1); }

void intPush(struct intStack *s, int data) {
    s->arr[++s->top] = data;
}

int intPop(struct intStack *s) {
    if (isIntEmpty(s)) {
        printf("Stack Underflow (int)\n");
        return 0;
    }
    return s->arr[s->top--];
}

// Utility functions
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

// Convert infix → postfix
char *infixToPostfix(char *infix, char *postfix) {
    struct stack s;
    s.top = -1;
    s.size = 50;
    s.arr = (char *)malloc(s.size * sizeof(char));

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char ch = infix[i];

        if (ch == '(') {
            push(&s, ch);
            i++;
        } else if (ch == ')') {
            while (!isEmpty(&s) && s.arr[s.top] != '(')
                postfix[j++] = pop(&s);
            if (!isEmpty(&s))
                pop(&s);
            i++;
        } else if (isOperator(ch)) {
            while (!isEmpty(&s) &&
                   ((precedence(ch) < precedence(s.arr[s.top])) ||
                    (precedence(ch) == precedence(s.arr[s.top]) && ch != '^'))) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
            i++;
        } else if (isalnum(ch)) {
            postfix[j++] = ch;
            i++;
        } else {
            i++; // ignore spaces or invalid chars
        }
    }

    while (!isEmpty(&s))
        postfix[j++] = pop(&s);

    postfix[j] = '\0';
    free(s.arr);
    return postfix;
}

// Evaluate postfix
int evaluatePostfix(char *postfix) {
    struct intStack s;
    s.top = -1;
    s.size = 50;
    s.arr = (int *)malloc(s.size * sizeof(int));

    int i = 0;
    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if (isdigit(ch)) {
            intPush(&s, ch - '0');
        } else if (isOperator(ch)) {
            int val2 = intPop(&s);
            int val1 = intPop(&s);
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
                default: result = 0;
            }
            intPush(&s, result);
        }
        i++;
    }

    int final = intPop(&s);
    free(s.arr);
    return final;
}

int main() {
    char infix[50], postfix[50];

    printf("Enter the Infix Expression (use single-digit operands):\n");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}
