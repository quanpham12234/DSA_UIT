#include <iostream>
using namespace std;

void Insert_sort(int a[], int n) // Insert : Chen. Do phuc tap O(n2)
{
    for (int i = 1; i < n;i++)
    {
        int pos = i - 1, x = a[i];

        while (pos >= 0 && a[pos] > x)
        {
            a[pos+1] = a[pos];
            pos--;
        }

        a[pos+1] = x;
    }
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Insert_sort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}