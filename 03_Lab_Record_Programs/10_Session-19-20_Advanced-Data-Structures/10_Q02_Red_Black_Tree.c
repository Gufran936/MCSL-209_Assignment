// Session-19 ( 3 hours) and Session-20 (3 hours): Advanced Data Structures

// Q2. Write a program in ‘C’ language for the creation of a Red Black tree. Also,
// implement insertion and deletion operations.

#include <stdio.h>
#include <stdlib.h>

enum Color
{
    RED,
    BLACK
};

// Structure for Red-Black Tree Node
struct Node
{
    int data;
    enum Color color;
    struct Node *left, *right, *parent;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->color = RED; // New nodes are always red initially
    node->left = node->right = node->parent = NULL;
    return node;
}

// Left Rotate
void rotateLeft(struct Node **root, struct Node *x)
{
    struct Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Right Rotate
void rotateRight(struct Node **root, struct Node *y)
{
    struct Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}

// Fix violations after insertion
void fixInsert(struct Node **root, struct Node *z)
{
    while (z != *root && z->parent->color == RED)
    {
        struct Node *grandparent = z->parent->parent;
        if (z->parent == grandparent->left)
        {
            struct Node *uncle = grandparent->right;
            if (uncle != NULL && uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    rotateLeft(root, z);
                }
                z->parent->color = BLACK;
                grandparent->color = RED;
                rotateRight(root, grandparent);
            }
        }
        else
        {
            struct Node *uncle = grandparent->left;
            if (uncle != NULL && uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rotateRight(root, z);
                }
                z->parent->color = BLACK;
                grandparent->color = RED;
                rotateLeft(root, grandparent);
            }
        }
    }
    (*root)->color = BLACK;
}

// Function to insert a value into Red-Black Tree
void insert(struct Node **root, int data)
{
    struct Node *z = createNode(data);
    struct Node *y = NULL;
    struct Node *x = *root;

    while (x != NULL)
    {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(root, z);
}

// Helper function to find the minimum node in a subtree
struct Node *minimum(struct Node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Simplified standard BST deletion / replacement for lab demonstration
struct Node *deleteNodeHelper(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNodeHelper(root->left, data);
    else if (data > root->data)
        root->right = deleteNodeHelper(root->right, data);
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            if (temp != NULL)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            if (temp != NULL)
                temp->parent = root->parent;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node *temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNodeHelper(root->right, temp->data);
    }
    return root;
}

// Function to handle deletion interface
void deleteNode(struct Node **root, int data)
{
    *root = deleteNodeHelper(*root, data);
    if (*root != NULL)
        (*root)->color = BLACK;
    printf("Successfully deleted %d (if it existed) from the Tree.\n", data);
}

// In-order traversal to print tree elements and colors
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d(%s) ", root->data, (root->color == RED) ? "RED" : "BLACK");
        inOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value, count;

    do
    {
        printf("\n--- Red-Black Tree Interactive Menu ---\n");
        printf("1. Insert Multiple Elements (Batch)\n");
        printf("2. Display Tree (In-order Traversal)\n");
        printf("3. Delete Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter how many values you want to insert: ");
            scanf("%d", &count);
            printf("Enter %d values separated by space or newline:\n", count);
            for (int i = 0; i < count; i++)
            {
                scanf("%d", &value);
                insert(&root, value);
            }
            printf("Successfully inserted %d elements into the Red-Black Tree.\n", count);
            break;
        case 2:
            printf("\nRed-Black Tree [Node(Color)]:\n");
            if (root == NULL)
            {
                printf("Tree is empty.\n");
            }
            else
            {
                inOrder(root);
                printf("\n");
            }
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(&root, value);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}