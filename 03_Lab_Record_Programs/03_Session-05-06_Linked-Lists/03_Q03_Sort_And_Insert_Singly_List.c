// Session-5 (3 hours) and Session-6 (3 hours) : Linked Lists

// Q3. Write a program in ‘C’ language to accept a singly linked list of integers as 
// input. Now, sort the elements of the list in ascending order. Then, accept an 
// integer as input. Insert this integer into the singly linked list at the appropriate 
// position.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of the list
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

// Function to sort the linked list in ascending order
void sortList(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to insert an integer into the sorted linked list at the appropriate position
void sortedInsert(struct Node **head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    // If list is empty or new node goes before head
    if (*head == NULL || (*head)->data >= val)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL && current->next->data < val)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
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
    struct Node *head = NULL;
    int n, i, val;

    printf("Enter number of elements in the linked list: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    printf("\nOriginal ");
    displayList(head);

    // Sort the list
    sortList(head);
    printf("Sorted ");
    displayList(head);

    // Accept an integer to insert
    printf("\nEnter an integer to insert at the appropriate position: ");
    scanf("%d", &val);
    sortedInsert(&head, val);

    printf("\nUpdated ");
    displayList(head);

    return 0;
}