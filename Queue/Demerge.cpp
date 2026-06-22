#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct NhanVien {
    string ten;
    char gioiTinh;
    int tuoi;
};

void demerging(vector<NhanVien>& danhSach) {
    // 1. Tạo 2 queue lưu trữ NhanVien
    queue<NhanVien> queueNu;
    queue<NhanVien> queueNam;
    
    // CODE CỦA BẠN Ở ĐÂY
    // 2. Phân loại danhSach vào queueNu và queueNam
    for (const NhanVien& nv : danhSach) 
    {
        if (nv.gioiTinh == 'F')
            queueNu.push(nv);

        else
            queueNam.push(nv);
    }    
    // 3. Lấy dữ liệu từ queue gộp lại vào danhSach
    int i = 0;
    while (!queueNu.empty()) {
        danhSach[i++] = queueNu.front();
        queueNu.pop();
    }

    
    while (!queueNam.empty()) {
        danhSach[i++] = queueNam.front();
        queueNam.pop();
    }
}

int main() {
    // Danh sách mẫu đã sắp xếp theo tuổi tăng dần (20 -> 20 -> 22 -> 25)
    vector<NhanVien> danhSach = {
        {"Binh", 'M', 20},
        {"Hoa", 'F', 20},
        {"Lan", 'F', 22},
        {"Tuan", 'M', 25}
    };

    cout << "--- Truoc khi Demerging ---" << endl;
    for (const auto& nv : danhSach) {
        cout << nv.ten << " - " << nv.gioiTinh << " - " << nv.tuoi << endl;
    }

    demerging(danhSach);

    cout << "\n--- Sau khi Demerging ---" << endl;
    for (const auto& nv : danhSach) {
        cout << nv.ten << " - " << nv.gioiTinh << " - " << nv.tuoi << endl;
    }

    return 0;
}