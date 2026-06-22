#include <iostream>

using namespace std;

// Node trong dslk đơn có 2 thành phần: giá trị và con trỏ next
struct Node
{
    int val;
    Node *next = nullptr;
};

// List trong dslk đơn có 2 thành phần: con trỏ head và con trỏ tail
struct List
{
    Node *head = nullptr;
    Node *tail = nullptr;
};

// Hàm tạo node mới với giá trị x
Node *makeNode(int x)
{
    Node *newNode = new Node;
    newNode->val = x;
    newNode->next = nullptr;

    return newNode;
}

// Hàm duyệt và in giá trị của các node trong dslk
void PrintList(List l)
{
    Node *p;
    p = l.head;

    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }
}

// Hàm tìm kiếm node có giá trị x trong dslk, trả về con trỏ đến node đó hoặc nullptr nếu không tìm thấy
Node *Search(List l, int x)
{
    Node *p;
    p = l.head;

    while (p != nullptr && p->val != x)
    {
        p = p->next;
    }

    return p;
}

// Hàm đếm số lượng node trong dslk
int Count(Node *head)
{
    int cnt = 0;
    while (head != nullptr)
    {
        cnt++;
        head = head->next;
    }

    return cnt;
}

// Hàm thêm node p vào đầu dslk
void add_Front_Node(List &l, Node *p)
{
    if (l.head == nullptr) // list rỗng
    {
        l.head = p;
        l.tail = l.head;
    }

    else
    {
        p->next = l.head;
        l.head = p;
    }
}

// Hàm thêm node p vào cuối dslk
void add_Back_Node(List &l, Node *p)
{
    if (l.head == nullptr)
    {
        l.head = p;
        l.tail = l.head;
    }

    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

// Hàm thêm node p vào sau node q trong dslk
void Insert_Node_After_Q(List &l, Node *p, Node *q)
{
    if (q != nullptr)
    {
        p->next = q->next;
        q->next = p;

        if (l.tail == q)
            l.tail = p;
    }

    else
        add_Back_Node(l, p);
}

// Hủy phần tử đứng đầu danh sách liên kết đơn
void Pop_front(List &l)
{
    if (l.head == nullptr)
        return;

    Node *p = l.head;
    l.head = l.head->next;

    if (l.head == nullptr)
        l.tail = nullptr;

    delete p;
}

// Hủy phần tử đứng sau phân tử q trong danh sách liên kết đơn
void Pop_front_after_q(List &l, Node *q)
{
    if (q == nullptr || q->next == nullptr)
        return;

    Node *p = q->next;

    if (l.tail == p)
        l.tail = q;

    q->next = p->next;
    delete p;
}

// Hủy phần tử có khóa x trong danh sách liên kết đơn
void Pop_X(List &l, int x)
{
    Node *p, *q = nullptr;
    p = l.head;

    while ((p != nullptr) && (p->val != x))
    {
        q = p;
        p = p->next;
    }

    if (p == nullptr)
        return;

    else if (q != nullptr)
        Pop_front_after_q(l, q);

    else
        Pop_front(l);
}

// Hủy danh sách liên kết đơn
void Remove_List(List &l)
{
    Node *p;
    while (l.head != nullptr)
    {
        p = l.head;
        l.head = p->next;
        delete p;
    }
}

// Sắp xếp danh sách liên kết đơn
void Selection_Sort(List &l)
{
    Node *p, *Min;
    p = l.head;

    while (p != nullptr) {
        Node *q = p->next;
        Min = p;

        while (q != nullptr) {
            if (q->val < p->val)
            {
                Min = q;
                q = q->next;
            }
        }

        swap(p->val,q->val);
        p = p->next;
    }
}

int main()
{
    List l;
    for (int i = 1; i <= 5; i++)
    {
        add_Back_Node(l, makeNode(i));
    }

    PrintList(l);
}