#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct SinhVien
{
    string MSSV;
    string HoTen;
    double DTB;

    void Thong_Tin()
    {
        cout << "MSSV: " << MSSV << "\n";
        cout << "Ho va ten: " << HoTen << "\n";
        cout << "DTB: " << DTB << "\n";
    }
};

struct Node
{
    SinhVien data;
    Node *next;
};

struct List
{
    Node *head = nullptr;
    Node *tail = nullptr;
};

// Tạo ra node từ cấu trúc sinh viên
Node *Create_Node(const SinhVien &x)
{
    Node *new_Node = new Node;
    new_Node->data = x;
    new_Node->next = nullptr;

    return new_Node;
}

// Thêm từng sinh viên vào đầu danh sách
void Add_Sinh_Vien(List &l, const SinhVien &x)
{
    Node *p = Create_Node(x);
    if (l.head == nullptr)
    {
        l.head = p;
        l.tail = p;
    }

    else
    {
        p->next = l.head;
        l.head = p;
    }
}

// Tìm một sinh viên có trong lớp hay không
Node *Co_trong_lop(const List& l, const string &MSSV) // Found: Trả về Node đó, còn không thì NULL
{
    Node *p = l.head;
    while (p != nullptr && p->data.MSSV != MSSV)
    {
        p = p->next;
    }

    return p;
}

// Xóa sinh viên thông qua mã sinh viên
void Xoa_Sinh_Vien(List &l, const string &MSSV)
{
    Node *p = l.head;
    Node *prev = nullptr;

    while (p != nullptr && p->data.MSSV != MSSV) {
        prev = p;
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Khong tim thay! \n";
        return;
    }

    if (p == l.head) {
        l.head = l.head->next;
    }

    else
        prev->next = p->next;

    if (p == l.tail)
        l.tail = prev;

    delete p;
}

// Liệt kê sinh viên có điểm trung bình lớn hơn hoặc bằng 5
void Liet_Ke_DTB_khong_duoi_5(const List &l)
{
    Node *p = l.head;
    bool found = false;
    while (p != nullptr)
    {
        if (p->data.DTB >= 5)
        {
            p->data.Thong_Tin();
            found = true;
        }
        p = p->next;
    }
    if (!found)
        cout << "Khong co sinh vien nao co dtb lon hon hoac bang 5! \n";

    return;
}

// Sắp xếp theo điểm trung bình tăng dần
void Selection_Sort(List &l) {
    Node *p = l.head;
    while (p != nullptr) {
        Node *Min = p;
        Node *q = p->next;
        while (q != nullptr) {
            if (q->data.DTB < Min->data.DTB)
                Min = q;
            q = q->next;
        }
        swap(p->data,Min->data);
        p = p->next;
    }
}

// Chèn sinh viên vào danh sách đã được xếp
void Insert(List &l, const SinhVien &sv) {
    Node*p = Create_Node(sv);
    
    if (l.head == nullptr || sv.DTB < l.head->data.DTB) {
        p->next = l.head;
        l.head = p;

        if (l.tail == nullptr) l.tail = p;
        return;
    }

    Node *q = l.head;

    while (q->next != nullptr && q->next->data.DTB < sv.DTB) {
        q = q->next;
    }

    p->next = q->next;
    q->next = p;

    if (p->next == nullptr) {
        l.tail = p;
    }
}

#include <limits>

int main()
{
    List l;

    cout << "===== NHAP DANH SACH SINH VIEN =====\n";
    while (true)
    {
        SinhVien sv;

        cout << "\nNhap MSSV: ";
        getline(cin, sv.MSSV);

        cout << "Nhap ho ten (de trong de dung): ";
        getline(cin, sv.HoTen);

        // 👉 điều kiện dừng
        if (sv.HoTen.empty())
            break;

        cout << "Nhap DTB: ";
        cin >> sv.DTB;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Add_Sinh_Vien(l, sv);
    }

    cout << "\n===== DANH SACH BAN DAU =====\n";
    Node *p = l.head;
    while (p != nullptr)
    {
        p->data.Thong_Tin();
        cout << "----------------\n";
        p = p->next;
    }

    // ===== TEST SORT =====
    cout << "\n===== SAP XEP =====\n";
    Selection_Sort(l);

    p = l.head;
    while (p != nullptr)
    {
        p->data.Thong_Tin();
        cout << "----------------\n";
        p = p->next;
    }

    // ===== TEST INSERT =====
    cout << "\n===== CHEN THEM 1 SINH VIEN =====\n";
    SinhVien newSV;
    cout << "Nhap MSSV: ";
    getline(cin, newSV.MSSV);
    cout << "Nhap ho ten: ";
    getline(cin, newSV.HoTen);
    cout << "Nhap DTB: ";
    cin >> newSV.DTB;
    cin.ignore();

    Insert(l, newSV);

    cout << "\nDanh sach sau khi chen:\n";
    p = l.head;
    while (p != nullptr)
    {
        p->data.Thong_Tin();
        cout << "----------------\n";
        p = p->next;
    }

    // ===== TEST XOA =====
    cout << "\n===== XOA SINH VIEN =====\n";
    string mssv;
    cout << "Nhap MSSV can xoa: ";
    cin >> mssv;

    Xoa_Sinh_Vien(l, mssv);

    cout << "\nDanh sach sau khi xoa:\n";
    p = l.head;
    while (p != nullptr)
    {
        p->data.Thong_Tin();
        cout << "----------------\n";
        p = p->next;
    }

    // ===== TEST TIM =====
    cout << "\n===== TIM SINH VIEN =====\n";
    cout << "Nhap MSSV can tim: ";
    cin >> mssv;

    Node *res = Co_trong_lop(l, mssv);
    if (res != nullptr)
        res->data.Thong_Tin();
    else
        cout << "Khong tim thay!\n";

    // ===== TEST LIET KE =====
    cout << "\n===== SV DTB >= 5 =====\n";
    Liet_Ke_DTB_khong_duoi_5(l);

    return 0;
}