/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io std::ios_base::sync_with_stdio(false)

// ###INSERT CODE HERE -
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int a[], int n, int i)
{
    int largest = i;

    if (2 * i + 1 < n && a[2 * i + 1] > a[largest])
        largest = 2 * i + 1;
    if (2 * i + 2 < n && a[2 * i + 2] > a[largest])
        largest = 2 * i + 2;

    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) // build Max Heap
        heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    fast_io;
    cin.tie(NULL);

    int n;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    heap_sort(a,n);

    for (int i = 0;i < n ;i++)
        cout << a[i] << " ";

    return 0;
}