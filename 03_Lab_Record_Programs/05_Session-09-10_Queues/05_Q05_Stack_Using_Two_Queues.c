// Session-9 (3 hours) and Session-10 (3 hours) : Queues

// Q5. Write a program in ‘C’ language to implement a stack using two queues.

#include <stdio.h>
#define MAX 100

struct Queue
{
    int arr[MAX];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

void enqueue(struct Queue *q, int val)
{
    if (q->rear == MAX - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = val;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
        return -1;
    int val = q->arr[q->front++];
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return val;
}

struct Queue q1, q2;

// Function to push an element into the stack (Make push operation costly)
void push(int val)
{
    // 1. Enqueue new element to q2
    enqueue(&q2, val);

    // 2. Move all elements from q1 to q2
    while (!isEmpty(&q1))
    {
        enqueue(&q2, dequeue(&q1));
    }

    // 3. Swap the names of q1 and q2
    struct Queue temp = q1;
    q1 = q2;
    q2 = temp;

    printf("Pushed: %d\n", val);
}

// Function to pop an element from the stack
void pop()
{
    if (isEmpty(&q1))
    {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    int popped = dequeue(&q1);
    printf("Popped: %d\n", popped);
}

// Function to display stack elements
void display()
{
    if (isEmpty(&q1))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (Top to Bottom): ");
    for (int i = q1.front; i <= q1.rear; i++)
    {
        printf("%d ", q1.arr[i]);
    }
    printf("\n");
}

int main()
{
    initQueue(&q1);
    initQueue(&q2);

    push(10);
    push(20);
    push(30);

    printf("\n");
    display();

    printf("\nPerforming Pop Operations:\n");
    pop();

    printf("\n");
    display();

    return 0;
}