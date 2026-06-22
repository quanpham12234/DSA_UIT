#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void Init_List(List &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}

Node *CreateNode(int x)
{
    Node *newNode = new Node;
    newNode->val = x;
    newNode->next = nullptr;

    return newNode;
}

void Traverse(const List &l)
{
    Node *p = l.pHead;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }
}

void AddTail(List &l, int x)
{
    Node *p = l.pTail;
    Node *q = CreateNode(x);
    if (l.pHead == nullptr)
    {
        l.pHead = q;
        l.pTail = q;
        return;
    }

    p->next = q;
    l.pTail = q;
}

void Reverse(List& l)
{
    Node *prev = nullptr;
    Node *cur = l.pHead;

    l.pTail = cur;

    while (cur != nullptr)
    {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    l.pHead = prev;
}

int main()
{
    List l;
    Init_List(l);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        AddTail(l, x);
    }

    Traverse(l);
    cout << "\n";

    Reverse(l);

    Traverse(l);
    cout << "\n";
    
    return 0;
}