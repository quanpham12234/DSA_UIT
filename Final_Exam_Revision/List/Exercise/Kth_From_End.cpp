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

Node *KthFromEnd(const List &l, int k)
{
    Node *left = l.pHead;
    Node *right = l.pHead;

    while (k--)
    {
        if (right == nullptr)
            return nullptr;
        right = right->next;
    }

    while (right != nullptr)
    {
        left = left->next;
        right = right->next;
    }

    return left;
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

    int k;
    cin >> k;
    Node *ans = KthFromEnd(l, k);

    if (ans != nullptr)
        cout << ans->val << "\n";

    return 0;
}