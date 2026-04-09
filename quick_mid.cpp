#include <iostream>
using namespace std;

int partition(int a[], int low, int high)
{
    int mid = (low + high) / 2;
    int pivot = a[mid]; 

    int i = low;
    int j = high;

    while (i <= j)
    {
        while (a[i] < pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    return i;   // returning partition index
}

void quickSort(int a[], int low, int high)
{
    if (low >= high)
        return;

    int index = partition(a, low, high);

    quickSort(a, low, index - 1);
    quickSort(a, index, high);
}

int main()
{
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}