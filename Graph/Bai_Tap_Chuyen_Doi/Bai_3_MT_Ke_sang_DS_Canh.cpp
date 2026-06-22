#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> Matrix(n, vector<int>(n));
    vector<pair<int,int>> edge;

    for (int i = 0;i < n ;i++) {
        for (int j = 0; j < n;j ++)
            cin >> Matrix[i][j];
    }

    for (int i = 0;i < n;i ++) {
        for (int j = i+1; j < n;j ++) {
            if (Matrix[i][j] == 1) {
                edge.push_back({i,j});
            }
        }
    }

    for (auto e : edge) {
        cout << e.first + 1 << " " << e.second + 1 << "\n";
    }

    return 0;
}