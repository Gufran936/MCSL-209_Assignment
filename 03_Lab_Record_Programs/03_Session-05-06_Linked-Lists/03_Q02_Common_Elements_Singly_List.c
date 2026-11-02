// Session-5 (3 hours) and Session-6 (3 hours) : Linked Lists

// Q2. Write a program in ‘C’ language that accepts two singly linked lists A and B as
// input. Now, print a singly linked list that consists of only those elements, which
// are common to both A and B.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of a list
void insertEnd(struct Node **head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to find common elements and store them in a new linked list
void findCommon(struct Node *a, struct Node *b, struct Node **common)
{
    struct Node *t1 = a;
    while (t1 != NULL)
    {
        struct Node *t2 = b;
        while (t2 != NULL)
        {
            if (t1->data == t2->data)
            {
                // Check if already added to avoid duplicates in common list
                struct Node *c = *common;
                int exists = 0;
                while (c != NULL)
                {
                    if (c->data == t1->data)
                    {
                        exists = 1;
                        break;
                    }
                    c = c->next;
                }
                if (!exists)
                {
                    insertEnd(common, t1->data);
                }
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}

// Function to display the linked list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *listA = NULL;
    struct Node *listB = NULL;
    struct Node *listCommon = NULL;
    int n1, n2, val, i;

    // Accept List A from user
    printf("Enter number of elements in List A: ");
    scanf("%d", &n1);
    printf("Enter elements for List A:\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &val);
        insertEnd(&listA, val);
    }

    // Accept List B from user
    printf("\nEnter number of elements in List B: ");
    scanf("%d", &n2);
    printf("Enter elements for List B:\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &val);
        insertEnd(&listB, val);
    }

    printf("\nList A: ");
    displayList(listA);

    printf("List B: ");
    displayList(listB);

    // Find common elements
    findCommon(listA, listB, &listCommon);

    printf("\nResultant Common Elements List:\n");
    displayList(listCommon);

    return 0;
}