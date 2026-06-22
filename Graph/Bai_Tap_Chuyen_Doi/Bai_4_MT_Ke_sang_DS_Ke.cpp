#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> Matrix(n, vector<int>(n));
    vector<int> adj[1001];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> Matrix[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;j ++) {
            if (Matrix[i][j] == 1) {
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
    }

    for (int i = 0 ;i < n; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < adj[i+1].size(); j++)
            cout << adj[i+1][j] << " ";

        cout << "\n";
    }

    return 0;
}