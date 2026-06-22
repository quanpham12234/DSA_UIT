#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void heapify(int a[],int n, int i)
{
    int largest = i;

    if (i * 2 + 1 < n && a[2*i+1] > a[largest])
    largest = 2 * i + 1;

    if (i * 2 + 2 < n && a[2*i+2] > a[largest])
    largest = 2 * i + 2;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a,n,largest);
    }
}

void Heap_sort(int a[],int n)
{
    for (int i = n/2 - 1; i >= 0; i--) // build Max Heap
    heapify(a,n,i);

    for (int i = n-1; i >= 0; i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0); // Rebuild Max Heap from head. Because all other roots ( != largest) are Max Heap
    }
}

int main()
{
    int a[1000];
    int n; cin >> n;
    srand(time(nullptr));
    for (int i =0 ; i < n; i++)
    a[i] = rand() % 1000;
    Heap_sort(a,n);
    for (int i = 0 ; i < n ;i++)
    cout << a[i] << " ";
    cout << endl;
    return 0;
}