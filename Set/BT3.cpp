#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int Test_Case;
    cin >> Test_Case;
    while (Test_Case--)
    {
        int m, n;
        cin >> m >> n;
        vector<long long> v(m);
        for (int i = 0; i < m; i++)
            cin >> v[i];

        set<long long> se;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            se.insert(x);
        }

        bool found = false;

        for (int i = 0; i < m; i++)
        {
            if (se.find(v[i]) == se.end())
            {
                cout << v[i] << " ";
                found = true;
            }
        }

        if (!found)
            cout << "NOT FOUND";

        cout << endl;
    }

    return 0;
}