#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n2 = nums2.size();
    unordered_map<int, int> temp;
    stack<int> st; // Stack: index

    for (int i = 0; i < n2; i++)
    {
        while (!st.empty() && nums2[st.top()] < nums2[i])
        {
            temp[nums2[st.top()]] = nums2[i];
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty())
    {
        temp[nums2[st.top()]] = -1;
        st.pop();
    }

    vector<int> ans;
    for (int x : nums1)
    {
        ans.push_back(temp[x]);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    int k;
    cin >> k;
    vector<int> q(k);
    for (int &x : q)
        cin >> x;

    vector<int> ans = nextGreaterElement(q, arr);

    for (int x : ans)
        cout << x << " ";

    return 0;
}