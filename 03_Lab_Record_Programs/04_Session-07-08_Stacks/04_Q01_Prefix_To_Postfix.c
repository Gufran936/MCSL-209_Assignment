// Session-7 (3 hours) and Session-8 (3 hours): Stacks

// Q1. Write a program in ‘C’ language to convert a prefix expression to a
// postfix expression using pointers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for stack node holding string operands
struct Node
{
    char data[100];
    struct Node *next;
};

// Function to push a string onto the stack using pointers
void push(struct Node **top, char *str)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, str);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a string from the stack and return dynamically allocated memory
char *pop(struct Node **top)
{
    if (*top == NULL)
        return NULL;
    struct Node *temp = *top;
    *top = (*top)->next;

    char *str = (char *)malloc(100 * sizeof(char));
    strcpy(str, temp->data);
    free(temp);
    return str;
}

// Function to check if a character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert prefix to postfix
void prefixToPostfix(char *prefix, char *postfix)
{
    struct Node *top = NULL;
    int length = strlen(prefix);

    // Scan prefix expression from right to left
    for (int i = length - 1; i >= 0; i--)
    {
        char symbol = prefix[i];

        // Skip whitespace if any
        if (isspace(symbol))
            continue;

        // If symbol is an operand, make it a string and push to stack
        if (isalnum(symbol))
        {
            char op[2] = {symbol, '\0'};
            push(&top, op);
        }
        // If symbol is an operator, pop two operands from stack
        else if (isOperator(symbol))
        {
            char *op1 = pop(&top);
            char *op2 = pop(&top);

            // Combine operands and operator: op1 + op2 + operator
            char temp[200];
            sprintf(temp, "%s%s%c", op1, op2, symbol);
            push(&top, temp);

            free(op1);
            free(op2);
        }
    }
    char *finalResult = pop(&top);
    strcpy(postfix, finalResult);
    free(finalResult);
}

int main()
{
    char prefix[100], postfix[100];

    printf("Enter a prefix expression (e.g., +AB): ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}