#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int b[100];
    int c[100];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (b[i] <= c[j])
        {
            i++;
            cout << "b" << i << " ";
        }
        else if (b[i] > c[j])
        {
            j++;
            cout << "c" << j << " ";
        }
    }
    while (i < m)
    {
        i++;
        cout << "b" << i << " ";
    }
    while (j < n)
    {
        j++;
        cout << "c" << j << " ";
    }
}