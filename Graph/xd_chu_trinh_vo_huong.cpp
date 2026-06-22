#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, st, e;
vector<int> adj[1001];
vector<int> visited(1001, false);
vector<int> parent(1001, 0);

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

bool dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            if (dfs(v))
                return true;
        }
        else if (v != parent[u])
        {
            st = u;
            e = v;
            return true;
        }
    }
    return false;
}

bool bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int x : adj[v]) {
            if (!visited[x]) {
                parent[x] = v;
                q.push(x);
            }
            else if (x != visited[v]) {
                st = x;
                e = v;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    input();
    for (int i = 1; i <= n; i++)
    {
        if (bfs(i) == true)
        {
            vector<int> cycle;
            int cur = st;

            while (cur != e)
            {
                cycle.push_back(cur);
                cur = parent[cur];
            }

            cycle.push_back(e);
            cycle.push_back(st);

            for (int x : cycle)
                cout << x << " ";

            return 0;
        }
    }

    return 0;
}