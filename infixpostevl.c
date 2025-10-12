#include <stdio.h>
#include <ctype.h>   
#include <string.h>  

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int j = 0;
    int len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        
        else if (ch == '(') {
            push(ch);
        }
       
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }

        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

// Main function
int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
