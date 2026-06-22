#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct Queue
{
    Node *front = nullptr;
    Node *back = nullptr;
};

Node *Create_Node(int x)
{
    Node *newNode = new Node;
    newNode->val = x;
    newNode->next = nullptr;

    return newNode;
}

bool isEmpty(const Queue &q)
{
    return q.front == nullptr;
}

void EnQueue(Queue &q, int x)
{
    Node *p = Create_Node(x);

    if (isEmpty(q))
    {
        q.front = p;
        q.back = p;
    }

    else
    {
        q.back->next = p;
        q.back = p;
    }
}

void DeQueue(Queue &q)
{
    if (isEmpty(q))
    {
        cout << "Hang doi rong! \n";
        return;
    }

    Node *p = q.front;
    q.front = p->next;

    if (q.front == nullptr)
    {
        q.back = nullptr;
    }

    delete p;
}

int Front(Queue &q)
{
    if (!isEmpty(q))
        return q.front->val;

    return -1;
}

int main()
{
    Queue q;
    EnQueue(q, 1);
    EnQueue(q, 5);
    EnQueue(q, -3);
    EnQueue(q, 6);
    EnQueue(q, 7);

    cout << Front(q) << "\n";

    DeQueue(q);
    cout << Front(q) << "\n";

    DeQueue(q);
    cout << Front(q) << "\n";
    
    DeQueue(q);
    cout << Front(q) << "\n";
    DeQueue(q);
    cout << Front(q) << "\n";
}