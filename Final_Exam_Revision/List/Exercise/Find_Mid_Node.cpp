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

Node *mid_Node(const List &l)
{
    Node *slow = l.pHead;
    Node *fast = l.pHead;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    Node* mid = mid_Node(l);

    if (mid != nullptr)
    cout << mid->val << "\n";

    return 0;
}