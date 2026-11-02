// Session-15 (3 hours) and Session-16 (3 hours) : Graphs

// Q3. Write a program in ‘C’ language to accept an undirected graph as input and
// print the list of all vertices in the Graph which are articulation points.

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

// Structure for Graph
struct Graph
{
    int V;
    struct AdjList *array;
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

// Add edge to undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Utility function for finding minimum
int findMin(int a, int b)
{
    return (a < b) ? a : b;
}

// Recursive function for DFS traversal and finding articulation points
void AP(int u, int visited[], int disc[], int low[], int parent[], int isAP[], struct Graph *graph)
{
    static int time = 0;
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    struct Node *pCrawl = graph->array[u].head;
    while (pCrawl != NULL)
    {
        int v = pCrawl->dest;

        if (!visited[v])
        {
            children++;
            parent[v] = u;
            AP(v, visited, disc, low, parent, isAP, graph);

            low[u] = findMin(low[u], low[v]);

            if (parent[u] == -1 && children > 1)
                isAP[u] = 1;

            if (parent[u] != -1 && low[v] >= disc[u])
                isAP[u] = 1;
        }
        else if (v != parent[u])
        {
            low[u] = findMin(low[u], disc[v]);
        }
        pCrawl = pCrawl->next;
    }
}

// Function to find articulation points in the graph
void findArticulationPoints(struct Graph *graph)
{
    int V = graph->V;
    int *visited = (int *)calloc(V, sizeof(int));
    int *disc = (int *)calloc(V, sizeof(int));
    int *low = (int *)calloc(V, sizeof(int));
    int *parent = (int *)malloc(V * sizeof(int));
    int *isAP = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            AP(i, visited, disc, low, parent, isAP, graph);
        }
    }

    printf("\nArticulation points (cut vertices) in the graph:\n");
    int found = 0;
    for (int i = 0; i < V; i++)
    {
        if (isAP[i] == 1)
        {
            printf("Vertex %d\n", i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No articulation points found.\n");
    }

    free(visited);
    free(disc);
    free(low);
    free(parent);
    free(isAP);
}

int main()
{
    int V, E, src, dest;

    printf("--- Undirected Graph Input ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    struct Graph *graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges in format (source destination) [0 to %d]:\n", V - 1);
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

    findArticulationPoints(graph);

    return 0;
}