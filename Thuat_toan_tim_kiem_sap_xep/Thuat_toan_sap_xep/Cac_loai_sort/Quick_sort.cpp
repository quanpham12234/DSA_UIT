#include <iostream>
#include <ctime>
#include <random>
using namespace std;

// Lomuto
int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}

void Quick_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = partition(a, l, r);
        Quick_sort(a, l, m - 1);
        Quick_sort(a, m + 1, r);
    }
}

// Hoare
int partition2(int a[], int l, int r)
{
    int pivot = a[l];

    int i = l - 1;
    int j = r + 1;

    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot);

        do
        {
            j--;
        } while (a[j] > pivot);

        if (i < j) swap(a[i],a[j]);

        else return j;
    }
}

void Quick_sort2(int a[], int l, int r)
{
    if (l >= r)
    return;
    int m = partition2(a,l,r);
    Quick_sort2(a,l,m);
    Quick_sort2(a,m+1,r);
}

int main()
{
    int a[1000];
    int n;
    cin >> n;
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000;
    Quick_sort2(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}