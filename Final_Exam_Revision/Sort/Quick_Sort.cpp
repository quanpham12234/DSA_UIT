#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Lomuto_Partition(vector<int> &arr, int l, int r)
{
    int n = arr.size();
    int pivot = arr[r];

    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[r]);

    return i;
}

int Hoare_Partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[l];

    int i = l - 1, j = r + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            break;

        swap(arr[i], arr[j]);
    }

    return j;
}

void Quick_Sort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int p = Lomuto_Partition(arr, l, r);
    Quick_Sort(arr, l, p - 1);
    Quick_Sort(arr, p + 1, r);
}

void Quick_Sort_2(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int p = Hoare_Partition(arr, l, r);
    Quick_Sort_2(arr, l, p);
    Quick_Sort_2(arr, p + 1, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Quick_Sort_2(arr, 0, n - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}