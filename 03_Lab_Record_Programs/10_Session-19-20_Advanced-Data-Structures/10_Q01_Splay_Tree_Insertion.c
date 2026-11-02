// Session-19 ( 3 hours) and Session-20 (3 hours): Advanced Data Structures

// Q1. Write a program in ‘C’ language to insert 15, 25, 2, 4, 3, 1, 50 into an initially
// empty Splay tree.

#include <stdio.h>
#include <stdlib.h>

// Definition of a Splay Tree Node
struct Node
{
    int key;
    struct Node *left, *right;
};

// Function to allocate a new node with given key
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Right rotate subtree rooted with y
struct Node *rightRotate(struct Node *x)
{
    struct Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay function: brings the key to the root if present, or brings the last accessed node to root
struct Node *splay(struct Node *root, int key)
{
    // Base cases: root is NULL or key is at root
    if (root == NULL || root->key == key)
        return root;

    // Key lies in the left subtree
    if (root->key > key)
    {
        // Key is not in tree, we're done
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key)
        {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (root->left->key < key)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key lies in the right subtree
    else
    {
        // Key is not in tree, we're done
        if (root->right == NULL)
            return root;

        // Zag-Zig (Right Left)
        if (root->right->key > key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (root->right->key < key)
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Function to insert a key into the Splay Tree
struct Node *insert(struct Node *root, int key)
{
    // If the tree is empty, return a new node
    if (root == NULL)
        return newNode(key);

    // Splay the given key to find where it should be inserted
    root = splay(root, key);

    // If key is already present, return root
    if (root->key == key)
        return root;

    // Allocate memory for new node
    struct Node *n = newNode(key);

    // If key is smaller than root, make root as right child of new node
    if (root->key > key)
    {
        n->right = root;
        n->left = root->left;
        root->left = NULL;
    }
    // If key is greater than root, make root as left child of new node
    else
    {
        n->left = root;
        n->right = root->right;
        root->right = NULL;
    }

    return n; // New node becomes the root
}

// Pre-order traversal of the tree
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int values[] = {15, 25, 2, 4, 3, 1, 50};
    int n = sizeof(values) / sizeof(values[0]);

    printf("--- Splay Tree Insertion ---\n");
    printf("Inserting elements: 15, 25, 2, 4, 3, 1, 50\n\n");

    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
        printf("Inserted %d -> Current Root: %d\n", values[i], root->key);
    }

    printf("\nPre-order traversal of the constructed Splay Tree:\n");
    preOrder(root);
    printf("\n");

    return 0;
}