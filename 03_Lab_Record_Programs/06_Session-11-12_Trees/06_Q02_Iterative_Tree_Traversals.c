// Session-11 (3 hours) and Session-12 (3 hours): Trees and Binary Trees

// Q2. Write a program in ‘C’ language for pre-order, post-order and in-order
// tranversals of a Binary tree. Don’t use Recursion.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Structure for Stack
struct Stack
{
    struct Node *arr[100];
    int top;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void push(struct Stack *s, struct Node *node)
{
    if (s->top < 99)
    {
        s->arr[++(s->top)] = node;
    }
}

struct Node *pop(struct Stack *s)
{
    if (isEmpty(s))
        return NULL;
    return s->arr[(s->top)--];
}

struct Node *peek(struct Stack *s)
{
    if (isEmpty(s))
        return NULL;
    return s->arr[s->top];
}

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Iterative Inorder Traversal (Left, Root, Right)
void iterativeInorder(struct Node *root)
{
    struct Stack s;
    initStack(&s);
    struct Node *curr = root;

    printf("Inorder Traversal:   ");
    while (curr != NULL || !isEmpty(&s))
    {
        while (curr != NULL)
        {
            push(&s, curr);
            curr = curr->left;
        }
        curr = pop(&s);
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

// Iterative Preorder Traversal (Root, Left, Right)
void iterativePreorder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Stack s;
    initStack(&s);
    push(&s, root);

    printf("Preorder Traversal:  ");
    while (!isEmpty(&s))
    {
        struct Node *curr = pop(&s);
        printf("%d ", curr->data);

        // Right child is pushed first so that left is processed first
        if (curr->right)
            push(&s, curr->right);
        if (curr->left)
            push(&s, curr->left);
    }
    printf("\n");
}

// Iterative Postorder Traversal using two stacks (Left, Right, Root)
void iterativePostorder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Stack s1, s2;
    initStack(&s1);
    initStack(&s2);

    push(&s1, root);
    while (!isEmpty(&s1))
    {
        struct Node *curr = pop(&s1);
        push(&s2, curr);

        if (curr->left)
            push(&s1, curr->left);
        if (curr->right)
            push(&s1, curr->right);
    }

    printf("Postorder Traversal: ");
    while (!isEmpty(&s2))
    {
        struct Node *curr = pop(&s2);
        printf("%d ", curr->data);
    }
    printf("\n");
}

int main()
{
    /* Constructing the following binary tree:
            1
          /   \
         2     3
        / \
       4   5
    */
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    iterativePreorder(root);
    iterativeInorder(root);
    iterativePostorder(root);

    return 0;
}