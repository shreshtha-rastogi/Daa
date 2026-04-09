#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int u, v, w;
} Edge;
Edge edges[MAX];
int parent[MAX];
int t[MAX][3];   // only 3 columns u, v and cost
/* ---------- Find Function ---------- */
int find(int i)
{
    int j=i;
    while(parent[j]>=0)
    {
        j=parent[j];
    }
    return j;
}
/* ---------- Union Function ---------- */
void Union(int u, int v)
{
    int a = find(u);
    int b = find(v);
    parent[a] = b;
}
/* ---------- Sort edges by cost ---------- */
void sortEdges(int e)
{
    int i, j;
    Edge temp;
    for(i = 0; i < e - 1; i++)
    {
        for(j = 0; j < e - i - 1; j++)
        {
            if(edges[j].w > edges[j + 1].w)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
/* ---------- Kruskal MST ---------- */
int kruskalMST(int e, int n)
{
    int i, j, k;
    int mincost = 0;
    int count = 0; // for no. of edges
    sortEdges(e);
    for(i = 0; i < n; i++)
        parent[i] = -1;
    i = 0;
    while(count < n - 1 && i < e)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int cost = edges[i].w;
        i++;
        j = find(u);
        k = find(v);
        if(j != k)
        {
            t[count][0] = u;
            t[count][1] = v;
            t[count][2] = cost;
            mincost += cost;
            count++;
            Union(u, v);
        }
    }
    if(count < n - 1)
    {
        printf("No MST exists\n");
        return -1;
    }
    printf("\nEdges in MST (with cost):\n");
    for(i = 0; i < count; i++)
        printf("%d - %d  cost = %d\n",t[i][0], t[i][1], t[i][2]);
    return mincost;
}
/* ---------- Main ---------- */
int main()
{
    int n, e, i;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    printf("Enter edges (u v cost):\n");
    for(i = 0; i < e; i++)
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
    int mincost = kruskalMST(e, n);
    if(mincost != -1)
        printf("Minimum cost of MST = %d\n", mincost);
    return 0;
}


