// Session-9 (3 hours) and Session-10 (3 hours) : Queues

// Q3. Write a program in ‘C’ language to reverse the elements of a queue.

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = val;
}

// Function to remove an element from the queue
int dequeue()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }
    int val = queue[front];
    front++;
    if (front > rear)
    {
        front = rear = -1; // Reset queue when empty
    }
    return val;
}

// Function to reverse the queue using a stack approach
void reverseQueue()
{
    int stack[MAX];
    int top = -1;

    // Transfer all elements from queue to stack
    while (front != -1)
    {
        stack[++top] = dequeue();
    }

    // Transfer all elements back from stack to queue (reversing the order)
    while (top != -1)
    {
        enqueue(stack[top--]);
    }
}

// Function to display the queue
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original ");
    display();

    // Reverse the queue
    reverseQueue();

    printf("Reversed ");
    display();

    return 0;
}