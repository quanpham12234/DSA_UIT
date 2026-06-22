#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int type;
    list<int> ans;
    
    int sz = 0; 

    while (cin >> type) {
        if (type == 4) {
            break;
        } 
        else if (type == 0) {
            int num;
            cin >> num;
            ans.push_front(num);
            sz++;
        } 
        else if (type == 1) {
            int num;
            cin >> num;
            ans.push_back(num);
            sz++;
        } 
        else if (type == 2) {
            int a, b;
            cin >> a >> b;
            auto it = find(ans.begin(), ans.end(), a);
            
            if (it == ans.end()) {
                ans.push_front(b);
            } else {
                ans.insert(next(it), b);
            }
            sz++; 
        } 
        else if (type == 3) {
            int k;
            cin >> k;
            if (sz > 0) {
                k = k % sz; 
                
                if (k > 0) {
                    auto it = ans.begin();
                    advance(it, k); // Duyệt it đi k bước
                    ans.splice(ans.end(), ans, ans.begin(), it);
                }
            }
        }
    }

    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}