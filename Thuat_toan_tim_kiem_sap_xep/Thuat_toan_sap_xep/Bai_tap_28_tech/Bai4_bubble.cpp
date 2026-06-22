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
    int buoc = 1;

    for (int i = n-1; i >= 0;i--)
    {
        bool Swap = false;
        for (int j = 0 ; j < i ;j++)
        {
            if (a[j+1] < a[j])
            {swap(a[j+1],a[j]);
            Swap = true;}
        }
        if (Swap == true)
        {
            cout << "Buoc " << buoc++ << ": ";
            output(a,n);
        }
        else
        break;
    }
    return 0;
    
}