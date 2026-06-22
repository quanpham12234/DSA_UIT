#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Hàm quy đổi chuỗi ưu tiên thành mức độ (0 -> 4)
int get_priority(const string& type) {
    if (type == "ambulance") return 4;
    if (type == "fire") return 3;
    if (type == "army") return 2;
    if (type == "police") return 1;
    return 0; // civilian
}

void solve() {
    int l, m;
    // Đọc liên tục các test case cho đến khi hết file
    while (cin >> l >> m) {
        long long L = l * 100LL; // Chuyển chiều dài phà từ mét sang cm
        
        // q[bờ][mức ưu tiên]: 
        // Bờ: 0 = Trái (left), 1 = Phải (right)
        // Mức ưu tiên: 0 đến 4
        queue<long long> q[2][5]; 
        
        for (int i = 0; i < m; ++i) {
            long long len;
            string type, bank_str;
            cin >> len >> type >> bank_str;
            
            int p = get_priority(type);
            // Bắt ký tự đầu tiên để tránh lỗi typo như "leftt" trong ví dụ 1
            int b = (bank_str[0] == 'l' || bank_str[0] == 'L') ? 0 : 1; 
            
            q[b][p].push(len);
        }
        
        int trips = 0;
        int current_bank = 0; // 0 là bờ trái (tả ngạn)
        
        while (true) {
            // Bước 1: Kiểm tra xem còn bất kỳ xe nào đang chờ ở cả 2 bờ không
            bool has_cars = false;
            for (int b = 0; b < 2; ++b) {
                for (int p = 0; p < 5; ++p) {
                    if (!q[b][p].empty()) has_cars = true;
                }
            }
            if (!has_cars) break; // Nếu hết xe rồi thì kết thúc
            
            // Bước 2: Nạp xe lên phà từ bờ hiện tại
            long long cap = L; // Sức chứa còn lại của phà
            bool blocked = false; // Cờ chặn nạp xe
            
            // Ưu tiên nạp xe mức 4 (ambulance) trước, giảm dần đến 0 (civilian)
            for (int p = 4; p >= 0; --p) {
                if (blocked) break; // Bị kẹt bởi xe lớn ở nhóm trên thì không xét nhóm dưới nữa
                
                while (!q[current_bank][p].empty()) {
                    if (q[current_bank][p].front() <= cap) {
                        cap -= q[current_bank][p].front();
                        q[current_bank][p].pop();
                    } else {
                        // Xe ưu tiên cao này không vừa phà => Dừng ngay lập tức!
                        blocked = true;
                        break;
                    }
                }
            }
            
            // Bước 3: Đưa phà qua sông
            trips++;
            current_bank = 1 - current_bank; // Đổi bờ (0 thành 1, 1 thành 0)
        }
        
        // In ra số chuyến đi của test case
        cout << trips << "\n";
    }
}

int main() {
    // Tối ưu hóa I/O để chương trình chạy cực nhanh
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}