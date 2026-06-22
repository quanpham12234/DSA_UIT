#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> b(n);
    stack<int> st;
    int res = 0;
    int i = 0;
    while (i < n)
    {
        if (st.empty() || a[i] >= a[st.top()])
        {
            st.push(i);
            i++;
        }
        else
        {
            int index = st.top();
            st.pop();
            if (st.empty())
                res = max(res, a[index] * i);
            else
                res = max(res, a[index] * (i - st.top() - 1));
        }
    }
    while (!st.empty())
    {
        int index = st.top();
        st.pop();
        if (st.empty())
            res = max(res, a[index] * n);
        else
            res = max(res, a[index] * (n - st.top() - 1));
    }

    cout << "Dien tich lon nhat: " << res << endl;
    return 0;
}
