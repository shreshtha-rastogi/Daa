#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int wt;
    struct node *next;
}node;

node *head = NULL;

/* create new node */
node* createnode(int w)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->wt = w;
    temp->next = NULL;
    return temp;
}

/* insert node in linked list */
void insert(node *nn)
{
    nn->next = head;
    head = nn;
}

/* find and delete minimum node */
node* least()
{
    node *temp = head;
    node *min = head;
    node *prev = NULL;
    node *minprev = NULL;

    while(temp != NULL)
    {
        if(temp->wt < min->wt)
        {
            min = temp;
            minprev = prev;
        }

        prev = temp;
        temp = temp->next;
    }

    /* delete min node */
    if(minprev == NULL)
        head = min->next;
    else
        minprev->next = min->next;

    min->next = NULL;
    return min;
}

/* optimal merge function */
int optimal(int files[], int n)
{
    int i;

    /* create linked list */
    for(i=0;i<n;i++)
    {
        node *nn = createnode(files[i]);
        insert(nn);
    }

    for(i=1;i<=n-1;i++)
    {
        node *left = least();
        node *right = least();

        node *nn = createnode(left->wt + right->wt);

        insert(nn);
    }

    node *res = least();
    return res->wt;
}

int main()
{
    int n, files[20], i;

    printf("Enter number of files: ");
    scanf("%d",&n);

    printf("Enter file sizes:\n");
    for(i=0;i<n;i++)
        scanf("%d",&files[i]);

    printf("Optimal cost of merging files is %d", optimal(files,n));

    return 0;
}