// Enrollment number : 2552562140
// Name              : Gufran

// Course Code       : MCSL-209
// Course Title      : Data Structures and Algorithms Lab
// Assignment Number : BCA_NEW/BCAOL(III)L-209/Assign/2026-27

// Q1: Write an algorithm and program in ‘C’ language that accepts a Graph as input and prints its adjacency
// matrix and adjacency list.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Structure for adjacency list */
struct Node
{
    int vertex;
    struct Node *next;
};

/* Function to create a new node */
struct Node *createNode(int v)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

int main()
{
    int n, e;
    int i, j;
    int u, v;

    int adjMatrix[MAX][MAX];

    struct Node *adjList[MAX];
    struct Node *newNode;
    struct Node *temp;

    /* Read number of vertices */
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    /* Initialize matrix and adjacency lists */
    for (i = 1; i <= n; i++)
    {
        adjList[i] = NULL;
        for (j = 1; j <= n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    /* Read number of edges */
    printf("Enter number of edges: ");
    scanf("%d", &e);

    /* Read edges */
    printf("Enter the edges (u v):\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);

        /* Adjacency Matrix */
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        /* Adjacency List */
        newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    /* Display Adjacency Matrix */
    printf("\nAdjacency Matrix:\n\n");

    printf("   ");
    for (i = 1; i <= n; i++)
        printf("%d ", i);

    printf("\n");

    for (i = 1; i <= n; i++)
    {
        printf("%d: ", i);

        for (j = 1; j <= n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }

        printf("\n");
    }

    /* Display Adjacency List */
    printf("\nAdjacency List:\n\n");

    for (i = 1; i <= n; i++)
    {
        printf("%d -> ", i);

        temp = adjList[i];

        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }

    return 0;
}