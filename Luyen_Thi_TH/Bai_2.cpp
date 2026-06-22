#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<int> st;
    int cnt = 0;

    for (int i =  0;i < n;i ++) {
        int key;
        cin >> key;

        int index = key % m;
        if (st.count(index) != 0) {
            cnt++;
            continue;
        }
        
        st.insert(index);
    }

    double ti_le = (double) cnt / n;
    if (ti_le > 0.33) {
        cout << "BAD";
    }
    else
        cout << "GOOD";


    return 0;
}