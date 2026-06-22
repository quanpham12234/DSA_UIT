#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
    int k,n ; cin >> k >> n;
    if (k == 0 || n == 0) return 0;

    list<int> recent;
    unordered_map<int, int> cnt;
    unordered_map<int,list<int>::iterator> pos;

    while (n--) {
        int x; cin >> x;
        
        cnt[x]++;

        if (pos.count(x) != 0) {
            recent.erase(pos[x]);
        }

        recent.push_front(x);
        pos[x] = recent.begin();
    }

    while (k-- && !recent.empty()) {
        cout << recent.front();
        if (cnt[recent.front()] != 1) {
            cout << "(" << cnt[recent.front()] << ")";
        }
        cout << " ";
        recent.pop_front();
    }

    return 0;
}