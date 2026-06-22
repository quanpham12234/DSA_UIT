#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[1001];

    while (m--) {
        int i, j;
        cin >> i >> j;
        adj[i-1].push_back(j);
        adj[j-1].push_back(i);
    }

    for (int i = 0;i < n; i++) {
        cout << i+1 << ": ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}