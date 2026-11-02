// Session-5 (3 hours) and Session-6 (3 hours) : Linked Lists

// Q1. Write a program in ‘C’ language for the creation of a list. Also, write a 
// procedure for deletion of an element from the list. Use pointers.
// You have to write the above program separately for Singly linked list, Doubly
// linked list and Circularly linked lists (both singly linked and doubly linked).
// Make necessary assumptions.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create and insert a node at the end of the list
void createList(struct Node **head, int val)
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

// Function to delete a node by value
void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head, *prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        printf("Element %d deleted successfully.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
    {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Element %d deleted successfully.\n", key);
}

// Function to display the linked list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    printf("Linked List: ");
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
    int choice, val;

    // Creating initial list with sample data
    createList(&head, 10);
    createList(&head, 20);
    createList(&head, 30);
    createList(&head, 40);

    printf("Initial List:\n");
    displayList(head);

    // Deleting an element
    printf("\nEnter element to delete: ");
    scanf("%d", &val);
    deleteNode(&head, val);

    printf("\nUpdated ");
    displayList(head);

    return 0;
}