#include <iostream>
#include <ctime>
#include <random>
#include <vector>

using namespace std;

void Merge(int a[], int l, int r)
{
    int m = (l + r) / 2;

    vector<int> left(a + l, a + m + 1);
    vector<int> right(a + m + 1, a + r + 1);

    int i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        a[l++] = left[i++];
        else
        a[l++] = right[j++];
    }

    while (i < left.size())
    a[l++] = left[i++];

    while (j < right.size())
    a[l++] = right[j++];
}

void Merge_sort(int a[], int l, int r)
{
    if (l >= r)
    return;
    int m = (l + r)/2;
    Merge_sort(a,l,m);
    Merge_sort(a,m+1,r);
    Merge(a,l,r);
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    Merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}