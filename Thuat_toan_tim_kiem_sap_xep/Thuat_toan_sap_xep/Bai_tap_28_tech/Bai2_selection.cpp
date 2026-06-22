#include <iostream>
using namespace std;

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min_pos] > a[j])
                min_pos = j;
        }
        swap(a[i], a[min_pos]);
        cout << "Buoc " << i + 1 << ": ";
        output(a, n);
    }
}