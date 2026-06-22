#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        priority_queue<int,vector<int>, greater<int>> pq;
        for (int i = 0;i < n ;i++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }

        int sum = 0;

        while (pq.size() > 1)
        {
            int temp = 0;
            temp += pq.top();
            pq.pop();
            temp += pq.top();
            pq.pop();
            pq.push(temp);
            sum += temp;
        }

        cout << sum << endl;
    }
    return 0;
}