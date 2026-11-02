// Session-7 (3 hours) and Session-8 (3 hours): Stacks

// Q2. Write a program in ‘C’ language to reverse an input string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};

// Function to push a character onto the stack
void push(struct Node **top, char c)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a character from the stack
char pop(struct Node **top)
{
    if (*top == NULL)
        return '\0';
    struct Node *temp = *top;
    char c = temp->data;
    *top = (*top)->next;
    free(temp);
    return c;
}

int main()
{
    struct Node *top = NULL;
    char str[100];

    printf("Enter a string to reverse: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline if present
    str[strcspn(str, "\n")] = '\0';

    int length = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < length; i++)
    {
        push(&top, str[i]);
    }

    // Pop characters from the stack to get the reversed string
    for (int i = 0; i < length; i++)
    {
        str[i] = pop(&top);
    }

    printf("Reversed string: %s\n", str);

    return 0;
}