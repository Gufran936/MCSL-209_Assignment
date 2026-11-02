// Session-11 (3 hours) and Session-12 (3 hours): Trees and Binary Trees

// Q3. Write a program in ‘C’ language to accept a tree as input and convert it into a
// binary tree. Print the resultant binary tree.

#include <stdio.h>
#include <stdlib.h>

// Structure for General Tree Node (can have multiple children)
struct GeneralNode
{
    int data;
    int numChildren;
    struct GeneralNode **children;
};

// Structure for Binary Tree Node (Left: First Child, Right: Next Sibling)
struct BinaryNode
{
    int data;
    struct BinaryNode *left;
    struct BinaryNode *right;
};

// Function to create a general tree node dynamically via user input
struct GeneralNode *createGeneralTree()
{
    int data, numChildren;

    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct GeneralNode *newNode = (struct GeneralNode *)malloc(sizeof(struct GeneralNode));
    newNode->data = data;

    printf("Enter number of children for %d: ", data);
    scanf("%d", &numChildren);

    newNode->numChildren = numChildren;
    if (numChildren > 0)
    {
        newNode->children = (struct GeneralNode **)malloc(numChildren * sizeof(struct GeneralNode *));
        printf("Enter children for %d:\n", data);
        for (int i = 0; i < numChildren; i++)
        {
            printf("Child %d of %d:\n", i + 1, data);
            newNode->children[i] = createGeneralTree();
        }
    }
    else
    {
        newNode->children = NULL;
    }

    return newNode;
}

// Function to create a binary tree node
struct BinaryNode *createBinaryNode(int data)
{
    struct BinaryNode *newNode = (struct BinaryNode *)malloc(sizeof(struct BinaryNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to convert a General Tree to a Binary Tree (Left-Child Right-Sibling method)
struct BinaryNode *convertToBinaryTree(struct GeneralNode *gRoot)
{
    if (gRoot == NULL)
        return NULL;

    struct BinaryNode *bRoot = createBinaryNode(gRoot->data);

    if (gRoot->numChildren > 0 && gRoot->children != NULL)
    {
        // First child becomes the left child in the binary tree
        bRoot->left = convertToBinaryTree(gRoot->children[0]);

        // Subsequent children become right siblings of each other
        struct BinaryNode *curr = bRoot->left;
        for (int i = 1; i < gRoot->numChildren; i++)
        {
            curr->right = convertToBinaryTree(gRoot->children[i]);
            curr = curr->right;
        }
    }
    return bRoot;
}

// Inorder traversal of the resultant binary tree
void inorder(struct BinaryNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    printf("--- Construct General Tree ---\n");
    struct GeneralNode *root = createGeneralTree();

    // Convert to Binary Tree
    struct BinaryNode *binaryRoot = convertToBinaryTree(root);

    printf("\nInorder traversal of the converted Binary Tree: ");
    inorder(binaryRoot);
    printf("\n");

    return 0;
}