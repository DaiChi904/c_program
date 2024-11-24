#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 教科書 p.21~22 に対応
#define MAX_GRAPH_SIZE 30 // The maximum size which this program can process.

// 隣接行列用のデータ構造の定義
typedef int AdjacencyMatrix[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE]; // テキストでは変数定義になっているが,ここでは型として宣言

// 隣接リスト用のデータ構造の定義
typedef int VertexIndex;

typedef struct EdgeCell
{                            // 有向辺のデータ構造
    VertexIndex destination; // 有向辺の終点 destination
    struct EdgeCell *next;   // 始点を同じくする,他の有向辺へのポインタ
} EdgeCell;

typedef EdgeCell *vertices[MAX_GRAPH_SIZE];

// テキストを参考にしたのはここまで

typedef struct
{                  // グラフのデータ構造
    int vertexNum; // 頂点数
    int edgeNum;   // 辺の数
    vertices vtop; // 頂点のデータ構造
} Graph;

// 隣接行列をファイル datafile から読み込む
int readAdjacencyMatrix(char *datafile, AdjacencyMatrix mat)
{
    FILE *fp; // 入力データのファイルポインタ
    int vertexNum;
    VertexIndex src, dest;

    fp = fopen(datafile, "r");      // ファイルを開く
    fscanf(fp, "%d\n", &vertexNum); // 頂点数 の読み込み
    if (vertexNum > MAX_GRAPH_SIZE)
    {
        fprintf(stderr, "##### This programm cannot process the size of graph which over %d.\n", MAX_GRAPH_SIZE);
        exit(1);
    }
    for (src = 0; src < vertexNum; src++)
    {
        for (dest = 0; dest < vertexNum; dest++)
        {
            fscanf(fp, "%d\n", &mat[src][dest]); // 隣接行列の要素を1つずつ読み込む
        }
    }
    fclose(fp); // ファイルを閉じる

    return vertexNum;
}

// 辺の追加 辺は頂点番号 src から dest へ向う
void addEdge(Graph *g, VertexIndex src, VertexIndex dest)
{
    EdgeCell *edge = (EdgeCell *)malloc(sizeof(EdgeCell));
    edge->destination = dest;
    edge->next = g->vtop[src];
    g->vtop[src] = edge;
}

// 隣接行列からグラフを作成 (テキスト指定のデータ構造)
void translateIntoGraph(AdjacencyMatrix mat, Graph *g)
{
    // この関数を完成させよ
    // 隣接行列の要素が 1 なら有向辺があるということ → 有向辺を追加 (関数 addEdge を使う)

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
// グラフ g の使用しているメモリを解放
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

void rdfs(int start, int *reversedVisited, Graph *g, AdjacencyMatrix *mat)
{
    reversedVisited[start] = 1;
    for (int i = 0; i < g->vertexNum; i++)
    {
        if ((*mat)[i][start] && !reversedVisited[i])
        {
            rdfs(i, reversedVisited, g, mat);
        }
    }
}

int isStronglyConnected(int *visited, int *reversedVisited, Graph *g, AdjacencyMatrix *a)
{
    int start = 0;

    dfs(start, visited, g, a);

    for (int i = 0; i < g->vertexNum; i++)
    {
        if (!visited[i])
        {
            return 0; // 全ての頂点に到達していない
        }
    }

    rdfs(start, reversedVisited, g, a);

    for (int i = 0; i < g->vertexNum; i++)
    {
        if (!reversedVisited[i])
        {
            return 0; // 全ての頂点に到達していない
        }
    }

    return 1; // 全ての頂点に到達している
}

int main(int argc, char *argv[])
{
    char *datafile;    // 入力データのファイル名
    AdjacencyMatrix a; // テキストでは大文字 A で定義
    Graph g;
    if (argc <= 1)
    {
        fprintf(stderr, "#####ファイル名を指定してください\n");
        return 1;
    }
    datafile = argv[1]; // ファイル名の取得
    g.vertexNum = readAdjacencyMatrix(datafile, a);
    translateIntoGraph(a, &g);

    int visited[MAX_GRAPH_SIZE] = {0};
    int reversedVisited[MAX_GRAPH_SIZE] = {0};

    if (isStronglyConnected(visited, reversedVisited, &g, &a))
    {
        printf("y\n");
    }
    else
    {
        printf("n\n");
    }

    freeGraph(&g); // グラフのデータ格納場所を解放
    return 0;
}
