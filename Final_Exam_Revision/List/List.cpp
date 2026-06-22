#include <iostream>
#include <algorithm>

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

Node *Search(const List &l, int x)
{
    Node *p = l.pHead;

    while (p != nullptr && p->val != x)
        p = p->next;

    return p;
}

void AddHead(List &l, int x)
{
    Node *p = l.pHead;
    Node *q = CreateNode(x);
    if (p == nullptr)
    {
        l.pHead = q;
        l.pTail = q;
        return;
    }

    q->next = p;
    l.pHead = q;
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

void InsertAfterQ(List &l, Node *p, Node *q)
{
    if (q != nullptr)
    {
        p->next = q->next;
        q->next = p;

        if (l.pTail == q)
            l.pTail = p;
    }
}

void DeleteHead(List &l)
{
    Node *p = l.pHead;
    if (p == nullptr)
        return;

    l.pHead = p->next;

    if (l.pHead == nullptr)
        l.pTail = nullptr;

    delete p;
}

void DeleteTail(List &l)
{
    if (l.pHead == nullptr)
        return;

    if (l.pHead == l.pTail)
    {
        delete l.pHead;
        l.pHead = nullptr;
        l.pTail = nullptr;
        return;
    }

    Node *p = l.pHead;
    while (p->next != l.pTail)
    {
        p = p->next;
    }

    delete l.pTail;

    l.pTail = p;
    p->next = nullptr;
}

void RemoveX(List &l, int x)
{
    if (l.pHead == nullptr)
        return;

    if (l.pHead == l.pTail && l.pHead->val == x)
    {
        delete l.pHead;
        l.pHead = nullptr;
        l.pTail = nullptr;
        return;
    }

    if (l.pHead->val == x)
    {
        DeleteHead(l);
        return;
    }

    Node *p = l.pHead->next;
    Node *prev = l.pHead;

    while (p != nullptr && p->val != x)
    {
        prev = p;
        p = p->next;
    }

    if (p == nullptr)
        return;

    prev->next = p->next;

    if (p == l.pTail)
        l.pTail = prev;

    delete p;
}

void RemoveAfterQ(List &l, Node *q)
{
    if (l.pHead == nullptr)
        return;

    if (q != nullptr && q->next != nullptr)
    {
        Node *p = q->next;
        q->next = p->next;
        if (l.pTail == p)
            l.pTail = q;

        delete p;
    }
}

void Selection_Sort(List &l)
{
    Node *p = l.pHead;
    if (p == nullptr)
        return;

    while (p != nullptr)
    {
        Node *min = p;
        Node *q = p->next;

        while (q != nullptr) {
            if (q->val < min->val)
                min = q;

            q = q->next;
        }

        swap(min->val, p->val);
        p = p->next;
    }
}

int main()
{
    List l;
    Init_List(l);

    AddHead(l, 1);
    AddHead(l, 5);
    AddHead(l, 14);
    AddHead(l, 3);
    AddHead(l, 58);
    AddHead(l, 11);
    AddHead(l, 0);

    Traverse(l);
    cout << "\n";

    AddTail(l, 1);
    AddTail(l, 5);
    AddTail(l, 14);
    AddTail(l, 3);
    AddTail(l, 58);
    AddTail(l, 11);
    AddTail(l, 0);

    Traverse(l);
    cout << "\n";

    Node *find = Search(l, 1);
    if (find != nullptr)
        cout << "Found \n";

    else
        cout << "Not Found \n";

    DeleteHead(l);

    Traverse(l);
    cout << "\n";

    DeleteTail(l);
    Traverse(l);
    cout << "\n";

    RemoveX(l, 58);
    Traverse(l);
    cout << "\n";

    Selection_Sort(l);
    Traverse(l);
    cout << "\n";

    return 0;
}
