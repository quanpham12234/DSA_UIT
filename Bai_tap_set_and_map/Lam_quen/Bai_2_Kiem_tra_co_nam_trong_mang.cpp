#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int Test_case;
    cin >> Test_case;
    while (Test_case--)
    {
        int n;
        cin >> n;
        map<int,bool> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x] = true;
        }
        int q; cin >> q;
        while(q--)
        {
            int y; cin >> y;
            if (mp[y] == true)
            cout << "YES" << endl;
            else
            cout << "NO" << endl;
        }
    }
    return 0;
}