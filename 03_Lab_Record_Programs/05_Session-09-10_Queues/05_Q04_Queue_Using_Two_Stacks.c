// Session-9 (3 hours) and Session-10 (3 hours) : Queues

// Q4. Write a program in ‘C’ language to implement a queue using two stacks.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Stack 1 operations
void push1(int data)
{
    if (top1 == MAX - 1)
    {
        printf("Stack 1 Overflow\n");
        return;
    }
    stack1[++top1] = data;
}

int pop1()
{
    if (top1 == -1)
        return -1;
    return stack1[top1--];
}

// Stack 2 operations
void push2(int data)
{
    if (top2 == MAX - 1)
    {
        printf("Stack 2 Overflow\n");
        return;
    }
    stack2[++top2] = data;
}

int pop2()
{
    if (top2 == -1)
        return -1;
    return stack2[top2--];
}

// Function to enqueue an element into the queue
void enqueue(int x)
{
    push1(x);
    printf("Enqueued: %d\n", x);
}

// Function to dequeue an element from the queue
void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    // If stack2 is empty, transfer all elements from stack1 to stack2
    if (top2 == -1)
    {
        while (top1 != -1)
        {
            push2(pop1());
        }
    }

    int removed = pop2();
    printf("Dequeued: %d\n", removed);
}

// Function to display the queue elements
void display()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    // Display elements in stack2 (from top to bottom)
    for (int i = top2; i >= 0; i--)
    {
        printf("%d ", stack2[i]);
    }
    // Display elements in stack1 (from bottom to top)
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("\n");
    display();

    printf("\nPerforming Dequeue:\n");
    dequeue();

    printf("\n");
    display();

    printf("\nEnqueuing another element:\n");
    enqueue(40);

    printf("\n");
    display();

    return 0;
}