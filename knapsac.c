#include <stdio.h>
typedef struct
{
    int id;
    float w, p;
} knap;

float x[50];   
void sort(knap obj[], int n)
{
    int i, j;
    knap temp;

    for(i = 1; i <= n-1; i++)
    {
        for(j = 1; j <= n-i; j++)
        {
            // compare p1/w1 and p2/w2 using cross multiplication
            if(obj[j].p * obj[j+1].w < obj[j+1].p * obj[j].w)
            {
                temp = obj[j];
                obj[j] = obj[j+1];
                obj[j+1] = temp;
            }
        }
    }
}


// fractional knapsack
void knapsack(knap obj[], float m, int n)
{
    int i;
    float u = m;   // remaining capacity

    for(i = 1; i <= n; i++)
        x[i] = 0;
    for(i = 1; i <= n; i++)
    {
        if(obj[i].w > u)
            break;

        x[i] = 1;
        u = u - obj[i].w;
    }
    // take fraction of next object
    if(i <= n)
        x[i] = u / obj[i].w;
}
int main()
{
    knap obj[51];   
    int n, i;
    float m;
    float Profit = 0;
    printf("Enter number of objects: ");
    scanf("%d", &n);
    printf("Enter capacity of knapsack: ");
    scanf("%f", &m);
    printf("\nEnter id, profit and weight of %d objects:\n",n);
    for(i = 1; i <= n; i++)
    {
        printf("\nEnter id, profit and weight of object %d:\n",i);
        scanf("%d %f %f", &obj[i].id, &obj[i].p, &obj[i].w);
    }

    sort(obj, n);
    printf("\nSorted objects by profit/weight ratio:\n");
    for(i = 1; i <= n; i++)
    {
        printf("Object[%d] = Profit: %.2f, Weight: %.2f\n", obj[i].id, obj[i].p, obj[i].w);
    }
    knapsack(obj, m, n);

    printf("\nSolution Vector:\n");

    for(i = 1; i <= n; i++)
    {
        printf("Object[%d] = %.2f\n", obj[i].id, x[i]);
        Profit += x[i] * obj[i].p;
    }

    printf("\nMaximum Profit = %.2f\n", Profit);

    return 0;
}