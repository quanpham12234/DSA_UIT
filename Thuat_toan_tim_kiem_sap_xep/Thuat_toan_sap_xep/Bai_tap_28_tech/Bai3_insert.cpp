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
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n ;i++)
    {
        int temp = a[i], pos = i -1;
        while (pos >= 0 && temp < a[pos])
        {
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = temp;
        cout << "Buoc " << i << ": ";
        for (int j = 0; j <= i; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}