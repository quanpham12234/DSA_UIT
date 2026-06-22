#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Binary_Search(vector<int> a, int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        if (x < a[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int x;
    cin >> x;

    cout << Binary_Search(a,n,x);

    return 0;
}