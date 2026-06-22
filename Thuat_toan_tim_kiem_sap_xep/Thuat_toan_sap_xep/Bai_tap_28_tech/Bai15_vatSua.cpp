#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > i)
            ans += a[i] - i;
        else
            break;
    }
    cout << ans << endl;
    return 0;
}