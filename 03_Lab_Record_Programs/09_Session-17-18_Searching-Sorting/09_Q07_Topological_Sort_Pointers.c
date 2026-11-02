// Session-17 (3 hours) and Session-18 (3 hours) : Searching and Sorting

// Q7. Write a program in ‘C’ language to implement Topological sort using pointers.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an adjacency list node
struct Node
{
    int dest;
    struct Node *next;
};

// Structure for adjacency list
struct AdjList
{
    struct Node *head;
};

// Structure for Directed Acyclic Graph (DAG)
struct Graph
{
    int V;
    struct AdjList *array;
};

// Stack structure implemented using pointers/arrays
struct Stack
{
    int items[MAX];
    int top;
};

// Function to create a graph node
struct Node *createNode(int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add a directed edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Stack helper functions
void initStack(struct Stack *s)
{
    s->top = -1;
}

int isStackEmpty(struct Stack *s)
{
    return s->top == -1;
}

void push(struct Stack *s, int value)
{
    if (s->top < MAX - 1)
    {
        s->items[++(s->top)] = value;
    }
}

int pop(struct Stack *s)
{
    if (isStackEmpty(s))
        return -1;
    return s->items[(s->top)--];
}

// Recursive DFS helper for Topological Sort using pointers
void topologicalSortUtil(int v, int *visited, struct Stack *s, struct Graph *graph)
{
    *(visited + v) = 1; // Mark the current node as visited using pointer arithmetic

    // Recur for all the vertices adjacent to this vertex
    struct Node *pCrawl = graph->array[v].head;
    while (pCrawl != NULL)
    {
        int connectedVertex = pCrawl->dest;
        if (!*(visited + connectedVertex))
        {
            topologicalSortUtil(connectedVertex, visited, s, graph);
        }
        pCrawl = pCrawl->next;
    }

    // Push current vertex to stack which stores result
    push(s, v);
}

// Function to perform Topological Sort
void topologicalSort(struct Graph *graph)
{
    int V = graph->V;
    int *visited = (int *)calloc(V, sizeof(int));
    struct Stack s;
    initStack(&s);

    // Call the recursive helper function to store Topological Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
    {
        if (!*(visited + i))
        {
            topologicalSortUtil(i, visited, &s, graph);
        }
    }

    printf("\nTopological Sort Order:\n");
    while (!isStackEmpty(&s))
    {
        printf("%d ", pop(&s));
    }
    printf("\n");

    free(visited);
}

int main()
{
    int V, E, src, dest;

    printf("--- Topological Sort Using Pointers ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    struct Graph *graph = createGraph(V);

    printf("Enter number of directed edges: ");
    scanf("%d", &E);

    printf("Enter directed edges in format (source destination) [0 to %d]:\n", V - 1);
    for (int i = 0; i < E; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < V && dest >= 0 && dest < V)
        {
            addEdge(graph, src, dest);
        }
        else
        {
            printf("Invalid vertices! Please re-enter edge %d: ", i + 1);
            i--;
        }
    }

    topologicalSort(graph);

    return 0;
}