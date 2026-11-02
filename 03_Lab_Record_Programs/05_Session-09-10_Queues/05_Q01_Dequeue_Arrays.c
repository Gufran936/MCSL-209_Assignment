// Session-9 (3 hours) and Session-10 (3 hours) : Queues

// Q1. Write a program in ‘C’ language to implement a Dequeue using Arrays. All
// operations associated with a Dequeue are to be implemented.

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Function to insert at the front
void insertFront(int val)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow! Cannot insert %d at front.\n", val);
        return;
    }
    if (front == -1)
    { // Queue is initially empty
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    deque[front] = val;
    printf("Inserted %d at front.\n", val);
}

// Function to insert at the rear
void insertRear(int val)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow! Cannot insert %d at rear.\n", val);
        return;
    }
    if (front == -1)
    { // Queue is initially empty
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = val;
    printf("Inserted %d at rear.\n", val);
}

// Function to delete from the front
void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow! Queue is empty.\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front]);
    if (front == rear)
    { // Queue has only one element
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Function to delete from the rear
void deleteRear()
{
    if (front == -1)
    {
        printf("Deque Underflow! Queue is empty.\n");
        return;
    }
    printf("Deleted %d from rear.\n", deque[rear]);
    if (front == rear)
    { // Queue has only one element
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

// Function to display the deque
void display()
{
    if (front == -1)
    {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();

    deleteFront();
    display();

    insertRear(30);
    display();

    deleteRear();
    display();

    return 0;
}