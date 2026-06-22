#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long lower_bound(vector<long long> a, long long n, long long x)
{
    long long l = 0;
    long long r = n - 1;
    long long res = -1;
    while (l <= r)
    {
        long long m = (l + r) / 2;
        if (a[m] >= x)
        {
            r = m - 1;
            res = a[m];
        }
        else
        {
            l = m + 1;
        }
    }
    return res;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    while (k--)
    {
        int x;
        cin >> x;

        cout << lower_bound(a, n, x) << endl;
    }

    return 0;
}