#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    if (!(cin >> n)) return 0;
    
    vector<int> unique_vals;
    vector<int> last_pos;
    
    unique_vals.reserve(n);
    last_pos.reserve(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (unique_vals.empty() || unique_vals.back() != x) {
            unique_vals.push_back(x);
            last_pos.push_back(i);
        } else {
            last_pos.back() = i; 
        }
    }

    int q; 
    cin >> q;
    
    while (q--) {
        int x; 
        cin >> x;
        
        auto it = lower_bound(unique_vals.begin(), unique_vals.end(), x);
        
        if (it != unique_vals.end() && *it == x) {
            int idx = it - unique_vals.begin();
            cout << last_pos[idx] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}