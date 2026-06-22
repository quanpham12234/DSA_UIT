#include <iostream>
#include <algorithm>

using namespace std;

// sort
// greater<int>(): giam dan


int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n,greater<int>());
    for (int i = 0; i < n;i++)
    cout << a[i] << " ";

    return 0;
}