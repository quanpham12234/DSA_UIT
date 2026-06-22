#include <iostream>
using namespace std;

void Bubble_sort (int a[],int n) // Do phuc tap: O(n2)
{
    for (int i = 0; i < n ;i++)
    {
        for (int j = 0 ; j < n-1-i; j++)
        {
            if (a[j] > a[j+1])
            swap(a[j],a[j+1]);
        }
    }
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
        Bubble_sort(a,n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
        return 0;
}