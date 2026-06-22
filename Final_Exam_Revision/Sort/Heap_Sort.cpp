#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complexity:
// Best, Worst, Average: O(nLogn)

void heapify(vector<int> &arr, int i, int n)
{
    int largest = i;

    if (arr[2 * i + 1] > arr[largest] && 2 * i + 1 < n)
        largest = 2 * i + 1;

    if (arr[2 * i + 2] > arr[largest] && 2 * i + 2 < n)
        largest = 2 * i + 2;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}

void Heap_Sort(vector<int> &arr)
{
    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);

    // Sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Heap_Sort(arr);

    for (auto x : arr) {
        cout << x << " ";
    }

    return 0;
}