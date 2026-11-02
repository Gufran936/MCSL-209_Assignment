// Session-15 (3 hours) and Session-16 (3 hours) : Graphs

// Q4. Write a program in ‘C’ language which accepts a directed graph as input and
// prints all the strongly connected components of the Graph.

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

// Structure for Directed Graph
struct Graph
{
    int V;
    struct AdjList *array;
};

// Stack structure
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

// Stack operations
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

// DFS to fill stack by finishing times
void fillOrder(int v, int visited[], struct Stack *s, struct Graph *graph)
{
    visited[v] = 1;

    struct Node *pCrawl = graph->array[v].head;
    while (pCrawl != NULL)
    {
        int connectedVertex = pCrawl->dest;
        if (!visited[connectedVertex])
        {
            fillOrder(connectedVertex, visited, s, graph);
        }
        pCrawl = pCrawl->next;
    }
    push(s, v);
}

// Function to transpose the graph
struct Graph *getTranspose(struct Graph *graph)
{
    struct Graph *transposeGraph = createGraph(graph->V);
    for (int v = 0; v < graph->V; v++)
    {
        struct Node *pCrawl = graph->array[v].head;
        while (pCrawl != NULL)
        {
            addEdge(transposeGraph, pCrawl->dest, v);
            pCrawl = pCrawl->next;
        }
    }
    return transposeGraph;
}

// DFS utility for printing components
void DFSUtil(int v, int visited[], struct Graph *graph)
{
    visited[v] = 1;
    printf("%d ", v);

    struct Node *pCrawl = graph->array[v].head;
    while (pCrawl != NULL)
    {
        int connectedVertex = pCrawl->dest;
        if (!visited[connectedVertex])
        {
            DFSUtil(connectedVertex, visited, graph);
        }
        pCrawl = pCrawl->next;
    }
}

// Function to print all strongly connected components
void printStronglyConnectedComponents(struct Graph *graph)
{
    int V = graph->V;
    int *visited = (int *)calloc(V, sizeof(int));
    struct Stack s;
    initStack(&s);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            fillOrder(i, visited, &s, graph);
        }
    }

    struct Graph *transposeGraph = getTranspose(graph);

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    printf("\nStrongly Connected Components (SCCs):\n");
    int sccCount = 1;
    while (!isStackEmpty(&s))
    {
        int v = pop(&s);

        if (!visited[v])
        {
            printf("Component %d: ", sccCount++);
            DFSUtil(v, visited, transposeGraph);
            printf("\n");
        }
    }

    free(visited);
}

int main()
{
    int V, E, src, dest;

    printf("--- Directed Graph Input ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    struct Graph *graph = createGraph(V);

    printf("Enter number of edges: ");
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

    printStronglyConnectedComponents(graph);

    return 0;
}