#include <iostream>
#include <set>

using namespace std;

int main()
{
    int Test_Case; cin >> Test_Case;
    while (Test_Case--)
    {
        int n; cin >> n;
        set<long long> se;
        for (int i = 0;i < n ;i++)
        {
            long long x; cin >> x;
            se.insert(x);
        }
        int querries; cin >> querries;
        while (querries--)
        {
            int q; cin >> q;
            if (se.find(q) != se.end())
            cout << "YES" << endl;
            else
            cout << "NO" << endl;
        }
    }

    return 0;
}