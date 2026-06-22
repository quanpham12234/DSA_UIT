#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, n; cin >> v >> e >> n;
    
    vector<string> verticle;
    for (int i = 0;i < v; i++) {
        string c; cin >> c;
        verticle.push_back(c);
    }

    unordered_map<string, unordered_map<string,int>> adj;
    
    for (int i = 0; i < e; i++) {
        string x, y; cin >> x >> y;
        int w;
        cin >> w;
        adj[x][y] = w;
    }

    int choice;
    while (n--) {
        cin >> choice;
        if (choice == 1) {
            string u, i; cin >> u >> i;
            if (adj[u].count(i) != 0) {
                cout << adj[u][i];
            }
            else
                cout << "FALSE";

            cout << "\n";
        }

        else {
            string w; cin >> w;

            vector<int> weights;

            for (const string& c: verticle) {
                if (adj[w].count(c)) {
                    weights.push_back(adj[w][c]);
                }
            }

            if (!weights.empty()) {
                for (const int& c : weights) {
                    cout << c << " ";
                }
            }
            else   
                cout << "NONE";

            cout << "\n";
        }
    }

    return 0;
}