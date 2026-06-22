#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct List
{
    Node *head = nullptr;
    Node *tail = nullptr;
};

Node *Create_Node(int x)
{
    Node *newNode = new Node;
    newNode->val = x;
    newNode->next = nullptr;

    return newNode;
}

void Insert_Node(List &l, int x)
{
    Node *p = Create_Node(x);
    if (l.head == nullptr)
    {
        l.head = p;
        l.tail = p;
        return;
    }

    Node *q = l.head;

    if (q->val > x)
    {
        p->next = q;
        l.head = p;
        return;
    }

    while (q->next != nullptr && q->next->val < x)
    {
        q = q->next;
    }

    p->next = q->next;
    q->next = p;

    if (p->next == nullptr) {
        l.tail = p;
    }
}

int index(const List& l, int x) {
    Node* p = l.head;
    int cnt = 1;
    while (p != nullptr && p->val != x) {
        p = p->next;
        cnt++;
    }
    if (p == nullptr) return 0;
    return cnt;
}

int main()
{
    List l;
    int choice;
    while (true) {
        cin >> choice;
        int num;
        if (choice == 1) {
            cin >> num;
            Insert_Node(l, num);
        }

        else if (choice == 2) {
            cin >> num;
            cout << index(l,num) << "\n";
        }

        else if (choice == 0) {
            break;
        }
    }

    return 0;
}