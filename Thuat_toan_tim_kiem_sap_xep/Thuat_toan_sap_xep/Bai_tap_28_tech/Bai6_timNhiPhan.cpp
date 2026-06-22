#include <iostream>
using namespace std;

int main()
{
    int n,k; cin >> n >> k;
    int a[100];
    for (int i = 0; i < n ;i++)
    cin >> a[i];
    int l = 0;
    int r = n-1;
    bool found = false;
    while(l <= r)
    {
        int m = ( l + r)/2;
        if (a[m] == k)
        {
            found = true;
            break;
        }
        else if (a[m] > k)
        r = m-1;
        else
        l = m+1;
    }
    cout << found << endl;
    return 0;

}