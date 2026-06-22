#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int rev_binary_search(int a[],int n, int x)
{
    int l = 0;
    int r = n-1;

    while (l <= r)
    {
        int m = (l + r)/2;
        if (a[m] == x)
        return m;
        if (a[m] > x) l = m + 1;
        else r = m-1;
    }
    return -1;
}

int main()
{
    int n; cin >> n;
    int *a = new int[n];

    for (int i = 0;i < n ;i++)
    {
        cin >> a[i];
    }
    for (int i = 0;i  < n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int x; cin >> x;
    cout << rev_binary_search(a,n,x);

    return 0;
}