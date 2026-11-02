// Session-11 (3 hours) and Session-12 (3 hours): Trees and Binary Trees

// Q1. Write a program in ‘C’ language for the creation of a binary tree. Also, provide
// for insertion and deletion operations.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue structure for level-order operations
struct Queue
{
    struct Node *arr[100];
    int front, rear;
};

struct Node *dequeue(struct Queue *q)
{
    if (q->front == -1)
        return NULL;
    struct Node *node = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return node;
}

void enqueue(struct Queue *q, struct Node *node)
{
    if (q->rear == 99)
        return;
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = node;
}

// Function to insert an element into the binary tree using level-order traversal
void insert(struct Node **root, int data)
{
    struct Node *newNode = createNode(data);
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }

    struct Queue q = {.front = -1, .rear = -1};
    enqueue(&q, *root);

    while (q.front != -1)
    {
        struct Node *temp = dequeue(&q);

        if (temp->left != NULL)
        {
            enqueue(&q, temp->left);
        }
        else
        {
            temp->left = newNode;
            return;
        }

        if (temp->right != NULL)
        {
            enqueue(&q, temp->right);
        }
        else
        {
            temp->right = newNode;
            return;
        }
    }
}

// Function to delete the deepest node in the tree
void deleteDeepest(struct Node *root, struct Node *delNode)
{
    struct Queue q = {.front = -1, .rear = -1};
    enqueue(&q, root);

    struct Node *temp;
    while (q.front != -1)
    {
        temp = dequeue(&q);
        if (temp == delNode)
        {
            free(delNode);
            return;
        }
        if (temp->right)
        {
            if (temp->right == delNode)
            {
                free(delNode);
                temp->right = NULL;
                return;
            }
            enqueue(&q, temp->right);
        }
        if (temp->left)
        {
            if (temp->left == delNode)
            {
                free(delNode);
                temp->left = NULL;
                return;
            }
            enqueue(&q, temp->left);
        }
    }
}

// Function to delete a node with a given key from the binary tree
void deleteNode(struct Node **root, int key)
{
    if (*root == NULL)
        return;

    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        if ((*root)->data == key)
        {
            free(*root);
            *root = NULL;
            printf("Node %d deleted successfully.\n", key);
        }
        else
        {
            printf("Key %d not found.\n", key);
        }
        return;
    }

    struct Queue q = {.front = -1, .rear = -1};
    enqueue(&q, *root);

    struct Node *temp = NULL;
    struct Node *keyNode = NULL;
    struct Node *lastNode = NULL;

    while (q.front != -1)
    {
        lastNode = temp = dequeue(&q);

        if (temp->data == key)
        {
            keyNode = temp;
        }
        if (temp->left)
        {
            enqueue(&q, temp->left);
        }
        if (temp->right)
        {
            enqueue(&q, temp->right);
        }
    }

    if (keyNode != NULL)
    {
        int x = lastNode->data;
        keyNode->data = x;
        deleteDeepest(*root, lastNode);
        printf("Node %d deleted successfully.\n", key);
    }
    else
    {
        printf("Key %d not found in the tree.\n", key);
    }
}

// Inorder traversal to display the tree
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct Node *root = NULL;

    // Creating binary tree and inserting elements
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);

    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    // Deleting a node
    deleteNode(&root, 20);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}