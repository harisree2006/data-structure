#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) { // operand
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

// Evaluate postfix expression
int evalPostfix(char postfix[]) {
    int i;
    int st[SIZE];
    int t = -1;
    char ch;
    int val;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            st[++t] = ch - '0';
        } else if (isOperator(ch)) {
            int b = st[t--];
            int a = st[t--];

            switch (ch) {
                case '+': val = a + b; break;
                case '-': val = a - b; break;
                case '*': val = a * b; break;
                case '/': val = a / b; break;
                case '^': val = 1;
                          for (int j = 0; j < b; j++) val *= a;
                          break;
            }
            st[++t] = val;
        }
    }

    return st[t];
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter infix expression (single-digit operands): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evalPostfix(postfix);
    printf("Evaluated result: %d\n", result);

    return 0;
}