#include <iostream>
using namespace std;

// Do phuc tap: O(n+max) . Tuy nhien chi dung duoc voi mang > 0 va max < 10^7

int main()
{
    int a[100];
    int n;
    cin >> n;
    int m = 0;
    int count[1000] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        count[a[i]]++;
        m = max(m, a[i]);
    }
    for (int i = 0; i <=  m; i++)
    {
        if (count[i] != 0)
        for (int j = 1 ; j <= count[i]; j++)
        cout << i << " ";
    }
    return 0;
}