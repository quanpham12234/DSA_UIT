#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
vector<bool> visited(1001, false);

void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }

    dfs(1);
}