#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 50
char stack[MAX];
int top = -1;

void push(char x) { stack[++top] = x; }

char pop() { return stack[top--]; }

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch))
            postfix[k++] = ch; 
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); 
        } else { 
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
}

int evalPostfix(char postfix[]) {
    int s[MAX], t = -1;
    char ch;
    int i = 0, a, b;
    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch))
            s[++t] = ch - '0'; t
        else {
            b = s[t--];
            a = s[t--];
            switch (ch) {
                case '+': s[++t] = a + b; break;
                case '-': s[++t] = a - b; break;
                case '*': s[++t] = a * b; break;
                case '/': s[++t] = a / b; break;
                case '^': s[++t] = pow(a, b); break;
            }
        }
    }
    return s[t];
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression (use single-digit numbers): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    int result = evalPostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

