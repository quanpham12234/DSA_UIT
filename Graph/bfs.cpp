#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
vector<bool> visited(1001, false);

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int x : adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
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
        adj[y].push_back(x);
    }

    bfs(1);
}