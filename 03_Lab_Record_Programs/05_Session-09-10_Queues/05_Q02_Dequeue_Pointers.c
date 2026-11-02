// Session-9 (3 hours) and Session-10 (3 hours) : Queues

// Q2. Write a program in ‘C’ language to implement a Dequeue using pointers. All
// operations associated with a Dequeue are to be implemented.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Function to insert an element at the front
void insertFront(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    printf("Inserted %d at front.\n", val);
}

// Function to insert an element at the rear
void insertRear(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    printf("Inserted %d at rear.\n", val);
}

// Function to delete an element from the front
void deleteFront()
{
    if (front == NULL)
    {
        printf("Deque Underflow! Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Deleted %d from front.\n", temp->data);

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

// Function to delete an element from the rear
void deleteRear()
{
    if (rear == NULL)
    {
        printf("Deque Underflow! Queue is empty.\n");
        return;
    }
    struct Node *temp = rear;
    printf("Deleted %d from rear.\n", temp->data);

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}

// Function to display the deque
void display()
{
    if (front == NULL)
    {
        printf("Deque is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Deque elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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