#include <iostream>
#include <vector>

using namespace std;

// Complexity:
// Best, Worst, Ave: O(nLogn)
// Space: O(n)

void merge(vector<int> &arr, int l, int r, int m)
{
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0;
    int j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            arr[l++] = left[i++];
        }

        else
            arr[l++] = right[j++];
    }

    while (i < left.size())
    {
        arr[l++] = left[i++];
    }

    while (j < right.size())
    {
        arr[l++] = right[j++];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, r, m);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}