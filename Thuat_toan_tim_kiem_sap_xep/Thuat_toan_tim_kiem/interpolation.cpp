#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int interpolation_search(vector<int> a, int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (((r - l) * (x - a[l])) / (a[r] - a[l])) + l;
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

    cout << interpolation_search(a,n,x) << endl;
    
    return 0;
}