#include <iostream>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n, k;
        cin >> n >> k;
        int a[100];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int l = 0;
        int r = n - 1;
        int res = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m] == k)
            {
                res = m+1;
                l = m + 1;
            }
            else if (a[m] > k)
                r = m - 1;
            else
                l = m + 1;
        }
        cout << res << endl;
    }
    return 0;
}