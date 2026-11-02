// Session-11 (3 hours) and Session-12 (3 hours): Trees and Binary Trees

// Q4. Write a program in ‘C’ language to accept a binary tree as input and check if the
// input binary tree is a full binary tree or not.

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

// Function to check if a binary tree is a full binary tree
int isFullBinaryTree(struct Node *root)
{
    // If tree is empty, it is a full binary tree
    if (root == NULL)
        return 1;

    // If node has no children (leaf node), it is valid
    if (root->left == NULL && root->right == NULL)
        return 1;

    // If node has both left and right children, recursively check both subtrees
    if (root->left != NULL && root->right != NULL)
    {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }

    // If node has only one child, it is not a full binary tree
    return 0;
}

int main()
{
    printf("--- Construct Binary Tree ---\n");
    struct Node *root = createBinaryTree();

    if (isFullBinaryTree(root))
    {
        printf("\nThe given binary tree is a FULL Binary Tree.\n");
    }
    else
    {
        printf("\nThe given binary tree is NOT a Full Binary Tree.\n");
    }

    return 0;
}