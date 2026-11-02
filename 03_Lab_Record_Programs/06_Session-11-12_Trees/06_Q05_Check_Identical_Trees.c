// Session-11 (3 hours) and Session-12 (3 hours): Trees and Binary Trees

// Q5. Write a program in ‘C’ language to accept two trees as input and check if both
// of them are the same. Give the appropriate message.

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

// Function to check if two trees are identical
int areIdentical(struct Node *root1, struct Node *root2)
{
    // If both trees are empty, they are identical
    if (root1 == NULL && root2 == NULL)
        return 1;

    // If one is empty and the other is not, they are not identical
    if (root1 == NULL || root2 == NULL)
        return 0;

    // Check if current data matches and recursively check left and right subtrees
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

int main()
{
    printf("--- Construct First Tree ---\n");
    struct Node *root1 = createBinaryTree();

    printf("\n--- Construct Second Tree ---\n");
    struct Node *root2 = createBinaryTree();

    if (areIdentical(root1, root2))
    {
        printf("\nBoth trees are IDENTICAL.\n");
    }
    else
    {
        printf("\nBoth trees are NOT identical.\n");
    }

    return 0;
}