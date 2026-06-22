#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
vector<bool> visited(1001, 0);
vector<int> parent(1001, 0);

void dfs(int n)
{
    visited[n] = true;
    for (int x : adj[n])
    {
        if (!visited[x])
        {
            parent[x] = n;
            dfs(x);
        }
    }
}

void bfs(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int x : adj[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }
}

void path(int s, int t)
{
    bfs(s);
    if (!visited[t])
    {
        cout << "Khong co duong di tu " << s << " den " << t << "! \n";
    }

    else
    {
        vector<int> path;
        int temp = t;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        cout << "Duong di tu " << s << " den " << temp << ": ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];

            if (i != (path.size() -1 ))
            cout << " -> ";
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }

    int s, t;
    cin >> s >> t;

    path(s,t);

    return 0;
}