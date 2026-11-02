// Session-7 (3 hours) and Session-8 (3 hours): Stacks

// Q3. Write a program in ‘C’ language to implement multiple stacks in a
// single array.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

// Function to push into Stack 1 (grows from left to right)
void push1(int val)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow in Stack 1!\n");
        return;
    }
    arr[++top1] = val;
    printf("Pushed %d into Stack 1.\n", val);
}

// Function to push into Stack 2 (grows from right to left)
void push2(int val)
{
    if (top2 - 1 == top1)
    {
        printf("Stack Overflow in Stack 2!\n");
        return;
    }
    arr[--top2] = val;
    printf("Pushed %d into Stack 2.\n", val);
}

// Function to pop from Stack 1
void pop1()
{
    if (top1 == -1)
    {
        printf("Stack Underflow in Stack 1!\n");
        return;
    }
    printf("Popped %d from Stack 1.\n", arr[top1--]);
}

// Function to pop from Stack 2
void pop2()
{
    if (top2 == MAX)
    {
        printf("Stack Underflow in Stack 2!\n");
        return;
    }
    printf("Popped %d from Stack 2.\n", arr[top2++]);
}

// Function to display Stack 1
void display1()
{
    if (top1 == -1)
    {
        printf("Stack 1 is empty.\n");
        return;
    }
    printf("Stack 1 elements: ");
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to display Stack 2
void display2()
{
    if (top2 == MAX)
    {
        printf("Stack 2 is empty.\n");
        return;
    }
    printf("Stack 2 elements: ");
    for (int i = MAX - 1; i >= top2; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Demonstrating operations on two stacks in a single array
    push1(10);
    push1(20);
    push2(30);
    push2(40);

    printf("\n");
    display1();
    display2();

    printf("\nPerforming Pop Operations:\n");
    pop1();
    pop2();

    printf("\n");
    display1();
    display2();

    return 0;
}