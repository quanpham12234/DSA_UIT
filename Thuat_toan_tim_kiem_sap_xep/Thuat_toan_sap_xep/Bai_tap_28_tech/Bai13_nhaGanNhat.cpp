#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    cin >> a[i];
    sort(a,a+n);
    int res = 1000000;
    for (int i = 1; i < n; i++)
    res = min(res,a[i]-a[i-1]);
    cout << res << endl;
    return 0;
}