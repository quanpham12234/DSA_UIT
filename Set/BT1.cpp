#include <iostream>
#include <set>

using namespace std;

int main()
{
    int Test_Case; cin >> Test_Case;
    while (Test_Case--)
    {
        int n; cin >> n;
        set<long long> st;
        for (int i = 0;i < n ;i++)
        {
            long long x; cin >> x;
            st.insert(x);
        }

        cout << st.size() << endl;
    }

    return 0;
}