// Session-15 (3 hours) and Session-16 (3 hours) : Graphs

// Q2. Write a program in ‘C’ language to implement Kruskal’s algorithm.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
};

// Structure to represent a graph
struct Graph
{
    int V, E;
    struct Edge edges[MAX];
};

// Structure for Disjoint Set (Union-Find)
struct Subset
{
    int parent;
    int rank;
};

// Function to create a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

// Find set of an element i (with path compression)
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function that does union of two sets of x and y (by rank)
void Union(struct Subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else
    {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparison function for sorting edges in non-decreasing order of weight
int compareEdges(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight - b1->weight;
}

// Function to construct MST using Kruskal's algorithm
void kruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[MAX]; // Tries to store the resultant MST
    int e = 0;               // An index variable, used for result[]
    int i = 0;               // An index variable, used for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E)
    {
        // Step 2: Pick the smallest edge. Check if it forms a cycle.
        // If it doesn't form a cycle, include it in the result.
        struct Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);

        // If including this edge doesn't cause a cycle, include it
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the constructed MST
    printf("Following are the edges in the constructed Minimum Spanning Tree (MST):\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Total Cost of Minimum Spanning Tree: %d\n", minimumCost);

    free(subsets);
    free(graph);
}

int main()
{
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    struct Graph *graph = createGraph(V, E);

    // Add edge 0-1
    graph->edges[0].u = 0;
    graph->edges[0].v = 1;
    graph->edges[0].weight = 10;

    // Add edge 0-2
    graph->edges[1].u = 0;
    graph->edges[1].v = 2;
    graph->edges[1].weight = 6;

    // Add edge 0-3
    graph->edges[2].u = 0;
    graph->edges[2].v = 3;
    graph->edges[2].weight = 5;

    // Add edge 1-3
    graph->edges[3].u = 1;
    graph->edges[3].v = 3;
    graph->edges[3].weight = 15;

    // Add edge 2-3
    graph->edges[4].u = 2;
    graph->edges[4].v = 3;
    graph->edges[4].weight = 4;

    printf("Executing Kruskal's Algorithm...\n\n");
    kruskalMST(graph);

    return 0;
}