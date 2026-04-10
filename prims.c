#include <stdio.h>
#define INF 9999
#define MAX 20
void prims(int cost[MAX][MAX], int n)
{
    int near[MAX], t[MAX][2];
    int i, j, k, l, min, mincost = 0;
    // Step 1: Find minimum edge
    min = INF;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(cost[i][j] < min)
            {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }
    t[1][1] = k;
    t[1][2] = l;
    mincost += min;
    // Initialize near[]
    for(i = 1; i <= n; i++)
    {
        if(cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }
    // is loop me ham pata kar rahe hai.. ki jo vertex MST me add nahi hue hai... vo wale vertex MST me added vertex ke sabse kam door kaun hai...matlab har non mst vertex ka distance nikaal rahe hai mst wale vertex se... jo minimum doori par hoga.. that we will add in mst.
    near[k] = 0;
    near[l] = 0;
    // Remaining edges
    for(i = 2; i <= n-1; i++)
    {
        min = INF;
        for(j = 1; j <= n; j++)
        {
            if(near[j] != 0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }
        t[i][1] = k;
        t[i][2] = near[k];
        mincost += cost[k][near[k]];
        near[k] = 0;
        // Update near[]
        for(j = 1; j <= n; j++)
        {
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }
    // Print MST
    printf("\nEdges in MST (with cost):\n");
    for(i = 1; i <= n-1; i++)
    {
        printf("%d - %d  cost = %d\n",
               t[i][1], t[i][2], cost[t[i][1]][t[i][2]]);
    }
    printf("\nMinimum Cost = %d\n", mincost);
}
int main()
{
    int cost[MAX][MAX], n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost of edges in matrix (9999 for infinity):\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    prims(cost, n);
    return 0;
}


//output

// Enter number of vertices: 7
// Enter cost of edges in matrix (9999 for infinity):
// 9999 28 9999 9999 30 10 9999 28 9999 16 9999 9999 9999 14 9999 16 9999 12 9999 9999 9999 9999 9999 12 9999 22 9999 18 30 9999 9999 22 9999 25 24 10 9999 9999 9999 25 9999 9999 9999 14 9999 18 24 9999 9999

// Edges in MST (with cost):
// 1 - 6  cost = 10
// 5 - 6  cost = 25
// 4 - 5  cost = 22
// 3 - 4  cost = 12
// 2 - 3  cost = 16
// 7 - 2  cost = 14

// Minimum Cost = 99












