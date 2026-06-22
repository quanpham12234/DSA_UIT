#include <iostream>
using namespace std;

void qs(int a[], int l, int r)
{
    int i = l;
    int j = r;
    int pivot = a[r];
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            if (i != j)
                cout << i + 1 << " " << j + 1 << endl;
            i++;
            j--; 
        }
    }
    if (l < j)
        qs(a, l, j);
    if (i < r)
        qs(a, i, r);
}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    qs(a, 0, n - 1);
    output(a, n);
    return 0;
}