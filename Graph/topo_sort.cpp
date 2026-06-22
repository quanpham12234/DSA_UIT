#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[1001];
vector<bool> visisted(1001, false);
vector<int> topo;
vector<int> in(1001,0);

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
}

void dfs(int u)
{
    visisted[u] = true;
    for (int x : adj[u])
    {
        if (!visisted[x])
        {
            dfs(x);
        }
    }
    topo.push_back(u);
}

void kahn() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int x : topo ) {
        cout << x << " ";
    }
}

int main()
{
    input();
    // for (int i = 1; i <= n; i++)
    // {
    //     if (!visisted[i])
    //         dfs(i);
    // }

    // reverse(topo.begin(), topo.end());

    // for (int x : topo)
    //     cout << x << " ";

    kahn();

    return 0;
}