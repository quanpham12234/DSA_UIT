#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class ChainingHashMap {
private:
    // Cấu trúc Node để lưu trữ một cặp Key-Value
    struct Node {
        int key;
        string value;
    };

    int capacity; // Kích thước của mảng băm
    int size;     // Tổng số phần tử đang lưu trữ
    
    // Bảng băm: Là một mảng (vector), mỗi phần tử của mảng là một danh sách liên kết (list)
    vector<list<Node>> table; 

    // Hàm băm cơ bản: Phép chia lấy dư
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    // Khởi tạo bảng băm
    ChainingHashMap(int cap) {
        capacity = cap;
        size = 0;
        table.resize(capacity); // Cấp phát sẵn số lượng ô mảng
    }

    // 1. Thao tác chèn phần tử (Insert)
    void insert(int key, string value) {
        int index = hashFunction(key);
        
        // Bước 1: Kiểm tra xem key này đã tồn tại trong danh sách chưa
        // Nếu có rồi thì ta cập nhật value mới (đặc tính của Hash-Map là key phải duy nhất)
        for (auto& node : table[index]) {
            if (node.key == key) {
                node.value = value;
                return; // Cập nhật xong thì thoát
            }
        }
        
        // Bước 2: Nếu chưa có, ta tạo Node mới và đẩy vào đầu danh sách liên kết của ô đó
        table[index].push_front({key, value});
        size++;
    }

    // 2. Thao tác tìm kiếm (Search)
    string search(int key) {
        int index = hashFunction(key);
        
        // Duyệt qua danh sách liên kết tại ô 'index'
        for (auto& node : table[index]) {
            if (node.key == key) {
                return node.value; // Tìm thấy, trả về giá trị
            }
        }
        return "Khong tim thay"; // Duyệt hết danh sách mà không có
    }

    // 3. Thao tác xóa (Delete)
    bool remove(int key) {
        int index = hashFunction(key);
        
        // Dùng iterator để duyệt và xóa phần tử trong list một cách an toàn
        auto it = table[index].begin();
        while (it != table[index].end()) {
            if (it->key == key) {
                table[index].erase(it); // Cắt đứt Node này khỏi danh sách
                size--;
                return true; // Xóa thành công
            }
            it++;
        }
        return false; // Không tìm thấy phần tử để xóa
    }

    // Hàm hiển thị để trực quan hóa dữ liệu
    void display() {
        cout << "\n--- TRANG THAI BANG BAM (CHAINING) ---\n";
        for (int i = 0; i < capacity; i++) {
            cout << "O thu [" << i << "]: ";
            for (auto& node : table[i]) {
                cout << "{" << node.key << ": " << node.value << "} -> ";
            }
            cout << "NIL\n";
        }
        cout << "--------------------------------------\n";
    }
};

int main() {
    // Khởi tạo bảng băm có 5 ô
    ChainingHashMap myMap(5);

    // Chèn dữ liệu
    myMap.insert(101, "Nguyen Van A");
    myMap.insert(205, "Tran Thi B");
    myMap.insert(301, "Le Van C"); // 301 % 5 = 1. Sẽ đụng độ với 101 (101 % 5 = 1)
    myMap.insert(402, "Pham D");

    cout << "Sau khi chen:";
    myMap.display();

    // Tìm kiếm
    cout << "Tim sv co ma 205: " << myMap.search(205) << "\n";
    cout << "Tim sv co ma 999: " << myMap.search(999) << "\n";

    // Xóa dữ liệu (Thử xóa phần tử bị đụng độ)
    cout << "\nXoa sinh vien co ma 101...\n";
    myMap.remove(101);
    
    // In lại để xem kết quả
    myMap.display();
    
    // Kiểm tra xem phần tử đụng độ với 101 (là 301) có bị ảnh hưởng không
    cout << "Tim sv co ma 301 sau khi xoa 101: " << myMap.search(301) << "\n";

    return 0;
}