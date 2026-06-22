#include <iostream>
using namespace std;

int so_lan_trai(int a[],int n,int k)
{
    int l = 0;
    int r = n-1;
    int cnt = -1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (a[m] == k)
        {
            cnt = m;
            r = m -1;
        }
        else if (a[m] > k)
        r = m-1;
        else 
        l = m +1;
    }
    return cnt;
}

int so_lan_phai(int a[],int n,int k)
{
    int l = 0;
    int r = n-1;
    int cnt = -1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (a[m] == k)
        {
            cnt = m;
            l = m +1;
        }
        else if (a[m] > k)
        r = m-1;
        else 
        l = m +1;
    }
    return cnt;
}

int main()
{
    int test_Case;
    cin >> test_Case;
    while (test_Case--)
    {
        int n, k;
        cin >> n >> k;
        int a[100];
        for (int i = 0; i < n ; i++)
        cin >> a[i];
        if (so_lan_phai(a,n,k) != -1)
        cout << so_lan_phai(a,n,k) - so_lan_trai(a,n,k) + 1 << endl;
        else
        cout << so_lan_phai(a,n,k) - so_lan_trai(a,n,k) << endl;
    }
    return 0;
}
