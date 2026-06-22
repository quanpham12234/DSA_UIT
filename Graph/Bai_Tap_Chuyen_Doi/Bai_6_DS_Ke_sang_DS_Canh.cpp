#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n; cin >> n;
    cin.ignore();
    vector<pair<int,int>> edge;

    for (int i = 0;i < n; i++) {
        string s, num;
        getline(cin,s);
        stringstream ss(s);
        while(ss >> num) {
            if (stoi(num) > (i + 1))
                edge.push_back({i+1,stoi(num)});
        }
    }

    for (auto e : edge) {
        cout << e.first << " " << e.second << '\n';
    }

    return 0;
}