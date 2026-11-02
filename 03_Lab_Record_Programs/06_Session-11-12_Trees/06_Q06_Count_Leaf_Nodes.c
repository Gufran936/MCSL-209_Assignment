// Session-11 (3 hours) and Session-12 (3 hours): Trees and Binary Trees

// Q6. Write a program in ‘C’ language to count the number of leaves of a Binary tree.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new binary tree node dynamically via user input
struct Node *createBinaryTree()
{
    int data;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    printf("Enter left child of %d:\n", data);
    newNode->left = createBinaryTree();

    printf("Enter right child of %d:\n", data);
    newNode->right = createBinaryTree();

    return newNode;
}

// Function to count the number of leaf nodes in a binary tree
int countLeafNodes(struct Node *root)
{
    if (root == NULL)
        return 0;

    // If node is a leaf node (no left or right child), return 1
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursively count leaves in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main()
{
    printf("--- Construct Binary Tree ---\n");
    struct Node *root = createBinaryTree();

    int leafCount = countLeafNodes(root);
    printf("\nTotal number of leaf nodes in the binary tree: %d\n", leafCount);

    return 0;
}