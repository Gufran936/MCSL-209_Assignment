// Session-13 (3 hours) and Session-14 (3 hours) : Advanced trees

// Q2. Write a program in ‘C’ language to insert 15, 25, 2, 4, 3, 1, 50 into an initially
// empty AVL tree. Make assumptions, if necessary.

#include <stdio.h>
#include <stdlib.h>

// Node structure for AVL Tree
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of a node
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to get the maximum of two integers (renamed to avoid macro conflicts)
int getMax(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to allocate a new node with a given key
struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

// Right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = getMax(height(y->left), height(y->right)) + 1;
    x->height = getMax(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = getMax(height(x->left), height(x->right)) + 1;
    y->height = getMax(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted with node
struct Node *insert(struct Node *node, int key)
{
    // 1. Perform standard BST insertion
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + getMax(height(node->left), height(node->right));

    // 3. Get the balance factor to check if this node became unbalanced
    int balance = getBalance(node);

    // If unbalanced, evaluate the 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Preorder traversal of the AVL tree
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Inorder traversal of the AVL tree
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    // Values to be inserted into the AVL tree as specified in the lab manual: 15, 25, 2, 4, 3, 1, 50
    int values[] = {15, 25, 2, 4, 3, 1, 50};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserting sequence: 15, 25, 2, 4, 3, 1, 50 into AVL Tree...\n\n");
    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }

    printf("Preorder Traversal of the AVL Tree:\n");
    preOrder(root);
    printf("\n\n");

    printf("Inorder Traversal (Sorted Order) of the AVL Tree:\n");
    inOrder(root);
    printf("\n");

    return 0;
}