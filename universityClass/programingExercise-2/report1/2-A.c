#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ! Important: 0 means false, 1 means true 

// The maximum size which this program can process.
#define MAX_GRAPH_SIZE 30

typedef int AdjacencyMatrix[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];

typedef int VertexIndex;

typedef struct EdgeCell
{
    VertexIndex destination;
    struct EdgeCell *next;
} EdgeCell;

typedef EdgeCell *Vertices[MAX_GRAPH_SIZE];

typedef struct
{
    int vertexNum;
    int edgeNum;
    Vertices vtop;
} Graph;

// Import AdjacencyMatrix file from datafile.
int readAdjacencyMatrix(char *datafile, AdjacencyMatrix mat)
{
    FILE *fp;
    int vertexNum;
    VertexIndex src, dest;

    fp = fopen(datafile, "r");
    fscanf(fp, "%d\n", &vertexNum);
    if (vertexNum > MAX_GRAPH_SIZE)
    {
        fprintf(stderr, "##### This programm cannot process the size of graph which is over %d.\n", MAX_GRAPH_SIZE);
        exit(1);
    }
    for (src = 0; src < vertexNum; src++)
    {
        for (dest = 0; dest < vertexNum; dest++)
        {
            fscanf(fp, "%d\n", &mat[src][dest]);
        }
    }
    fclose(fp);

    return vertexNum;
}

// Add edge.
void addEdge(Graph *g, VertexIndex src, VertexIndex dest)
{
    EdgeCell *edge = (EdgeCell *)malloc(sizeof(EdgeCell));
    edge->destination = dest;
    edge->next = g->vtop[src];
    g->vtop[src] = edge;
}

// Create graph adjacency matrix.
void translateIntoGraph(AdjacencyMatrix mat, Graph *g)
{
    VertexIndex i, j;
    for (i = 0; i < g->vertexNum; i++)
    {
        g->vtop[i] = NULL;
    }
    for (i = 0; i < g->vertexNum; i++)
    {
        for (j = 0; j < g->vertexNum; j++)
        {
            if (mat[i][j] == 1)
            {
                addEdge(g, i, j);
            }
        }
    }
}

// Print graph.
void printGraph(Graph *g)
{
    VertexIndex v;
    printf("digraph G {\n");
    printf("  size=\"11.5,8\"; node[fontsize=10,height=0.01,width=0.01]; edge[len=3.0];\n");
    for (v = 0; v < g->vertexNum; v++)
    {
        EdgeCell *edge;
        for (edge = g->vtop[v]; edge != NULL; edge = edge->next)
        {
            printf("  %d -> %d;\n", v + 1, edge->destination + 1);
        }
    }
    printf("}\n");
}

// Free the memory which graph is using.
void freeGraph(Graph *g)
{
    VertexIndex v;
    for (v = 0; v < g->vertexNum; v++)
    {
        EdgeCell *edge, *next_edge;
        for (edge = g->vtop[v]; edge != NULL; edge = next_edge)
        {
            next_edge = edge->next;
            free(edge);
        }
    }
}

// Perform DFS 
void dfs(int start, int *visited, Graph *g, AdjacencyMatrix *mat)
{
    visited[start] = 1;
    for (int i = 0; i < g->vertexNum; i++)
    {
        if ((*mat)[start][i] && !visited[i])
        {
            dfs(i, visited, g, mat);
        }
    }
}

// Perform DFS
void reversedDfs(int start, int *reversedVisited, Graph *g, AdjacencyMatrix *mat)
{
    reversedVisited[start] = 1;
    for (int i = 0; i < g->vertexNum; i++)
    {
        if ((*mat)[i][start] && !reversedVisited[i])
        {
            reversedDfs(i, reversedVisited, g, mat);
        }
    }
}

// Check is passed adjacency matrix is strongly connected.
int isStronglyConnected(int *visited, int *reversedVisited, Graph *g, AdjacencyMatrix *a)
{
    int start = 0;

    dfs(start, visited, g, a);

    for (int i = 0; i < g->vertexNum; i++)
    {
        if (!visited[i])
        {
            return 0;
        }
    }

    reversedDfs(start, reversedVisited, g, a);

    for (int i = 0; i < g->vertexNum; i++)
    {
        if (!reversedVisited[i])
        {
            return 0;
        }
    }

    return 1; // Reached to all of vertex.
}

int main(int argc, char *argv[])
{
    char *datafile;
    AdjacencyMatrix a;
    Graph g;
    if (argc <= 1)
    {
        fprintf(stderr, "##### Please specify a file name.\n");
        return 1;
    }
    datafile = argv[1];
    g.vertexNum = readAdjacencyMatrix(datafile, a);
    translateIntoGraph(a, &g);

    int visited[MAX_GRAPH_SIZE] = {0};
    int reversedVisited[MAX_GRAPH_SIZE] = {0};

    if (isStronglyConnected(visited, reversedVisited, &g, &a))
    {
        printf("The adjacency matrix is strongly connected.\n");
    }
    else
    {
        printf("The adjacency matrix is not strongly connected.\n");
    }

    printGraph(&g);
    freeGraph(&g);
    return 0;
}
