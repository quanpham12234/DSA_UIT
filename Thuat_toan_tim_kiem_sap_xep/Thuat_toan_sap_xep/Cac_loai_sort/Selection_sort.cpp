#include <iostream>
using namespace std;

void Selection_sort(int a[], int n) // Xap xi O(n2)
{
    for (int i = 0; i < n; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_pos])
                min_pos = j;
        }
        swap(a[i], a[min_pos]);
    }
    return;
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Selection_sort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
        return 0;
}