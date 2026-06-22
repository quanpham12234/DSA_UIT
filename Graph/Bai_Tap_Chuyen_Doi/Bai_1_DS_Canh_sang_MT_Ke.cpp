#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m; // n: Số đỉnh, m: Số cạnh
    cin >> n >> m;
    vector<vector<int>> Matrix (n, vector<int> (n,0));

    while (m--) {
        int i, j;
        cin >> i >> j;
        Matrix[i-1][j-1] = 1;
        Matrix[j-1][i-1] = 1;
    }

    for (int i = 0;i < n; i++) {
        for (int j = 0;j < n;j ++)
            cout << Matrix[i][j] << " ";

        cout << "\n";
    }

    return 0;
}