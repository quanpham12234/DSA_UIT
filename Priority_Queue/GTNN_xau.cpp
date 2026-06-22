#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;

        unordered_map<char, int> mp;
        priority_queue<int> pq;

        for (char c : s)
        {
            mp[c]++;
        }

        for (auto it : mp)
            pq.push(it.second);

        long long ans = 0;

        while (k--)
        {
            int top = pq.top();
            pq.pop();
            top--;
            pq.push(max(top,0));
        }

        while (!pq.empty())
        {
            ans += (pq.top() * pq.top());
            pq.pop();      
        }
        cout << ans << endl;
    }

}