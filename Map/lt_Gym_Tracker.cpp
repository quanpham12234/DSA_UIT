#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Cấu trúc lưu trữ dữ liệu 1 buổi tập
struct GymRecord {
    string exercise; // Tên bài tập (Khóa - Key)
    int pr_weight;   // Mức tạ nặng nhất (Value)
    int reps;        // Số rep thực hiện được (Value)
    bool is_deleted; // Cờ đánh dấu Bia mộ (Tombstone)
    bool is_empty;   // Cờ đánh dấu ô trống

    // Constructor khởi tạo ô trống mặc định
    GymRecord() : exercise(""), pr_weight(0), reps(0), is_deleted(false), is_empty(true) {}
};

class GymTracker {
private:
    vector<GymRecord> table;
    int capacity;
    int current_size; // Số phần tử thực tế đang có (không tính bia mộ)

    // 2. Hàm băm đa thức cho chuỗi ký tự (Giống Pokedex)
    int hashFunction(string key) {
        long long hashValue = 0;
        long long p_pow = 1;
        const int p = 31;
        for (char c : key) {
            hashValue = (hashValue + c * p_pow) % capacity;
            p_pow = (p_pow * p) % capacity;
        }
        return (hashValue % capacity + capacity) % capacity;
    }

    // 3. Cơ chế BĂM LẠI (Rehashing) - Trái tim của Open Addressing thực tế
    void rehash() {
        int old_capacity = capacity;
        capacity *= 2; // Nhân đôi kích thước
        cout << "\n[HỆ THỐNG] Bang bam da day. Dang mo rong (Rehash) tu " 
             << old_capacity << " len " << capacity << " o...\n";

        // Tạo mảng mới rộng gấp đôi
        vector<GymRecord> new_table(capacity);
        
        // Chuyển dữ liệu từ mảng cũ sang mảng mới
        for (int i = 0; i < old_capacity; i++) {
            if (!table[i].is_empty && !table[i].is_deleted) {
                // Băm lại từng phần tử vào mảng mới
                string key = table[i].exercise;
                int j = 0;
                while (j < capacity) {
                    long long hashValue = 0;
                    long long p_pow = 1;
                    const int p = 31;
                    for (char c : key) {
                        hashValue = (hashValue + c * p_pow) % capacity;
                        p_pow = (p_pow * p) % capacity;
                    }
                    int index = ((hashValue % capacity + capacity) % capacity + j) % capacity;
                    
                    if (new_table[index].is_empty) {
                        new_table[index] = table[i];
                        break;
                    }
                    j++;
                }
            }
        }
        // Thay thế mảng cũ bằng mảng mới
        table = new_table;
    }

public:
    GymTracker(int cap) {
        capacity = cap;
        current_size = 0;
        table.resize(capacity);
    }

    // 4. Thêm / Cập nhật bài tập (Insert)
    void insert(string exercise, int weight, int reps) {
        // Kiểm tra Hệ số tải: Nếu > 0.7 thì mở rộng mảng
        if ((float)current_size / capacity >= 0.7) {
            rehash();
        }

        int index = hashFunction(exercise);
        int i = 0;
        int first_tombstone = -1; // Nhớ vị trí bia mộ đầu tiên gặp để tái sử dụng

        while (i < capacity) {
            int j = (index + i) % capacity;

            // Nếu gặp ô trống: Dừng lại. Chèn vào bia mộ đầu tiên (nếu có), hoặc chèn vào ô trống này.
            if (table[j].is_empty) {
                int insert_pos = (first_tombstone != -1) ? first_tombstone : j;
                table[insert_pos].exercise = exercise;
                table[insert_pos].pr_weight = weight;
                table[insert_pos].reps = reps;
                table[insert_pos].is_empty = false;
                table[insert_pos].is_deleted = false;
                current_size++;
                cout << "[Luu] Da ghi nhan PR moi cho bai: " << exercise << "\n";
                return;
            }

            // Nếu gặp đúng bài tập đã có: Cập nhật mức tạ
            if (!table[j].is_deleted && table[j].exercise == exercise) {
                table[j].pr_weight = weight;
                table[j].reps = reps;
                cout << "[Cap nhat] Da cap nhat PR cho bai: " << exercise << "\n";
                return;
            }

            // Ghi nhận bia mộ trên đường đi để lát nữa chèn đè lên
            if (table[j].is_deleted && first_tombstone == -1) {
                first_tombstone = j;
            }

            i++;
        }
    }

    // 5. Tra cứu bài tập (Search)
    void search(string exercise) {
        int index = hashFunction(exercise);
        int i = 0;

        while (i < capacity) {
            int j = (index + i) % capacity;

            if (table[j].is_empty) {
                cout << "[Tra cuu] Ban chua tung tap bai " << exercise << "!\n";
                return;
            }

            if (!table[j].is_deleted && table[j].exercise == exercise) {
                cout << "--- KY LUC (" << exercise << ") ---\n";
                cout << "Muc ta: " << table[j].pr_weight << " kg\n";
                cout << "So rep: " << table[j].reps << "\n";
                cout << "--------------------------\n";
                return;
            }
            i++;
        }
        cout << "[Tra cuu] Ban chua tung tap bai " << exercise << "!\n";
    }

    // 6. Xóa bài tập (Delete bằng Tombstone)
    void remove(string exercise) {
        int index = hashFunction(exercise);
        int i = 0;

        while (i < capacity) {
            int j = (index + i) % capacity;

            if (table[j].is_empty) break;

            if (!table[j].is_deleted && table[j].exercise == exercise) {
                table[j].is_deleted = true; // Đặt bia mộ
                current_size--;
                cout << "[Xoa] Da xoa lich su bai " << exercise << ".\n";
                return;
            }
            i++;
        }
        cout << "[Loi] Khong tim thay bai " << exercise << " de xoa!\n";
    }

    // Hiển thị trạng thái mảng
    void display() {
        cout << "\n=== TRANG THAI BO NHO GYM TRACKER (Cap: " << capacity << ") ===\n";
        for (int i = 0; i < capacity; i++) {
            cout << "[" << i << "]: ";
            if (table[i].is_empty) cout << "TRONG\n";
            else if (table[i].is_deleted) cout << "[BIA MO]\n";
            else cout << table[i].exercise << " (" << table[i].pr_weight << "kg)\n";
        }
        cout << "=================================================\n\n";
    }
};

int main() {
    // Khởi tạo mảng siêu nhỏ (chỉ 4 ô) để ép chương trình phải Rehash sớm
    GymTracker myGym(4);

    myGym.insert("Bench Press", 60, 8);
    myGym.insert("Squat", 80, 5);
    myGym.insert("Deadlift", 100, 3); 
    // ^ Chèn đến đây, 3/4 ô đã đầy (75% > 70%). Hệ thống sẽ tự động Rehash lên 8 ô!

    myGym.display();

    myGym.insert("Lat Pulldown", 50, 10);
    myGym.insert("Bicep Curl", 15, 12);

    myGym.display();

    myGym.search("Squat");

    // Thử xóa và in lại để thấy Bia mộ
    myGym.remove("Bench Press");
    myGym.display();

    return 0;
}