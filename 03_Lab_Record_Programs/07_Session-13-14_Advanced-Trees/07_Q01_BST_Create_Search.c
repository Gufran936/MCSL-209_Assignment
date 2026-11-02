// Session-13 (3 hours) and Session-14 (3 hours) : Advanced trees

// Q1. Write a program in ‘C’ language to create a binary search tree. Also, accept a
// key value and search for it in BST. Print the appropriate message as output.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new BST node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a key in the BST
struct Node *search(struct Node *root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
    {
        return root;
    }

    // Key is smaller than root's data
    if (key < root->data)
    {
        return search(root->left, key);
    }

    // Key is greater than root's data
    return search(root->right, key);
}

// Inorder traversal to display the BST (prints elements in ascending order)
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
    int n, val, key;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder traversal of BST (Sorted order): ");
    inorder(root);
    printf("\n");

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    struct Node *result = search(root, key);
    if (result != NULL)
    {
        printf("Key %d FOUND in the Binary Search Tree.\n", key);
    }
    else
    {
        printf("Key %d NOT found in the Binary Search Tree.\n", key);
    }

    return 0;
}