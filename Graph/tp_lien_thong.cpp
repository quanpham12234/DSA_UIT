#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
vector<bool> visited(1001, false);

void dfs(int n)
{
    visited[n] = true;
    cout << n << " ";

    for (int a : adj[n])
    {
        if (!visited[a])
            dfs(a);
    }
}

void bfs(int n) {
    queue<int> q;
    q.fron
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int x : adj[v]) {
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

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            cout << "Cac dinh o thanh phan thu " << count << " la: ";
            bfs(i);
            cout << "\n";
        }
    }

    cout << "So luong thanh phan lien thong: ";
    cout << count << endl;

    if (count == 1)
    {
        cout << "Do thi lien thong! \n";
    }

    else
        cout << "Do thi khong lien thong! \n";

    return 0;
}