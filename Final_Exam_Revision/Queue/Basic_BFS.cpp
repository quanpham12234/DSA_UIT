#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> adj[1001];
    vector<bool> visited(1001, false);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}