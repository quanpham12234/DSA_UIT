#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    int Test_case; cin >> Test_case;
    while (Test_case--)
    {
        int n,m; cin >> n >> m;
        int st[n];
        set<int> st2;
        for (int i = 0; i < n; i++)
        {
            cin >> st[i];
        }
        for (int i = 0 ;i <  m ;i++)
        {
            int x; cin >> x;
            st2.insert(x);
        }
        bool oke = false;
        for (int i = 0; i < n; i++)
        {
            if (st2.count(st[i]) == 0)
            {
                oke = true;
                cout << st[i] << " ";
            }
        }
        if (oke == false)
        cout << "NOT FOUND" << endl;

    }
}