#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// Khai báo bảng băm siêu tốc
typedef gp_hash_table<int, null_type> fast_set;

int main() {
    // Ép xung tốc độ nhập xuất (Cực kỳ quan trọng với bài có I/O lớn)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fast_set online_gamers;
    int a, b;

    while (cin >> a && a != 0) {
        cin >> b;
        if (a == 1) {
            // Game thủ b đăng nhập -> Băm vào bảng
            online_gamers.insert(b);
        } else if (a == 2) {
            // Kiểm tra game thủ b
            if (online_gamers.find(b) != online_gamers.end()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}