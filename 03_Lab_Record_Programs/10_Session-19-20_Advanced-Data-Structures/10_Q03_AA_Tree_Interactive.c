// Session-19 ( 3 hours) and Session-20 (3 hours): Advanced Data Structures

// Q3. Write a program in ‘C’ language for the creation of a AA-tree. Also, implement
// insertion and deletion operations.

#include <stdio.h>
#include <stdlib.h>

// Structure for an AA-tree Node
struct Node
{
    int data;
    int level;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->level = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Skew operation: Removes left horizontal links
struct Node *skew(struct Node *t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else if (t->left->level == t->level)
    {
        struct Node *L = t->left;
        t->left = L->right;
        L->right = t;
        return L;
    }
    return t;
}

// Split operation: Removes consecutive right horizontal links
struct Node *split(struct Node *t)
{
    if (t == NULL)
        return NULL;
    else if (t->right == NULL || t->right->right == NULL)
        return t;
    else if (t->level == t->right->right->level)
    {
        struct Node *R = t->right;
        t->right = R->left;
        R->left = t;
        R->level++;
        return R;
    }
    return t;
}

// Function to insert a value into the AA-tree
struct Node *insert(struct Node *t, int data)
{
    if (t == NULL)
        return createNode(data);

    if (data < t->data)
        t->left = insert(t->left, data);
    else if (data > t->data)
        t->right = insert(t->right, data);
    else
        return t; // Duplicate keys not allowed

    t = skew(t);
    t = split(t);
    return t;
}

// Function to find the successor / predecessor for deletion
struct Node *predecessor(struct Node *t)
{
    struct Node *curr = t->left;
    while (curr && curr->right != NULL)
        curr = curr->right;
    return curr;
}

struct Node *successor(struct Node *t)
{
    struct Node *curr = t->right;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

// Decrement level helper for deletion
void decreaseLevel(struct Node *t)
{
    int shouldBe = (t->left ? t->left->level : 0) < (t->right ? t->right->level : 0) ? (t->left ? t->left->level : 0) : (t->right ? t->right->level : 0);
    shouldBe++;
    if (shouldBe < t->level)
    {
        t->level = shouldBe;
        if (t->right && shouldBe < t->right->level)
        {
            t->right->level = shouldBe;
        }
    }
}

// Function to delete a value from the AA-tree
struct Node *deleteNode(struct Node *t, int data)
{
    if (t == NULL)
        return t;

    if (data < t->data)
        t->left = deleteNode(t->left, data);
    else if (data > t->data)
        t->right = deleteNode(t->right, data);
    else
    {
        // Leaf node or node with one child
        if (t->left == NULL && t->right == NULL)
        {
            free(t);
            return NULL;
        }
        else if (t->left == NULL)
        {
            struct Node *temp = successor(t);
            t->data = temp->data;
            t->right = deleteNode(t->right, temp->data);
        }
        else
        {
            struct Node *temp = predecessor(t);
            t->data = temp->data;
            t->left = deleteNode(t->left, temp->data);
        }
    }

    // Rebalancing tree after deletion
    decreaseLevel(t);
    t = skew(t);
    t->right = skew(t->right);
    if (t->right)
        t->right->right = skew(t->right->right);
    t = split(t);
    t->right = split(t->right);

    return t;
}

// In-order traversal to display the AA-tree
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d(L:%d) ", root->data, root->level);
        inOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value, count;

    do
    {
        printf("\n--- AA-Tree Interactive Menu ---\n");
        printf("1. Insert Elements (Batch)\n");
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
            printf("Enter %d values:\n", count);
            for (int i = 0; i < count; i++)
            {
                scanf("%d", &value);
                root = insert(root, value);
            }
            printf("Successfully inserted %d elements into the AA-tree.\n", count);
            break;
        case 2:
            printf("\nAA-Tree [Node(Level)]:\n");
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
            root = deleteNode(root, value);
            printf("Successfully deleted %d (if it existed) from the tree.\n", value);
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