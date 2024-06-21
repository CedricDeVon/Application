#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

int get_precedence(char c)
{
    /*
    Edge Cases:
    - c is negative
    - c is CHAR_MAX
    - c is -CHAR_MAX
    - c is an invalid arithmetic operator
    - c is a valid arithmetic operator
    */
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void prefix_to_postfix(const char* prefix_expression, char* postfix_expression) {
    int length = strlen(prefix_expression);
    char stack[MAX_SIZE];
    int top = -1;

    for (int i = length - 1; i >= 0; i--) {
        char current_char = prefix_expression[i];

        if (isalnum(current_char)) {
            postfix_expression[top + 1] = current_char;
            top++;
        } else if (is_operator(current_char)) {
            while (top >= 0 && get_precedence(stack[top]) >= get_precedence(current_char)) {
                postfix_expression[top + 1] = stack[top];
                top--;
            }
            top++;
            stack[top] = current_char;
        } else if (current_char == '(') {
            while (top >= 0 && stack[top] != ')') {
                postfix_expression[top + 1] = stack[top];
                top--;
            }
            top--; // Pop the closing bracket
        } else if (current_char == ')') {
            top++;
            stack[top] = current_char;
        } else {
            printf("Invalid character in the expression\n");
            exit(1);
        }
    }

    while (top >= 0) {
        postfix_expression[top + 1] = stack[top];
        top--;
    }

    postfix_expression[top + 1] = '\0';
}
