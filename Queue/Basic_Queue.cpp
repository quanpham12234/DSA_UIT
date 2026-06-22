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

void Duyet(const Queue &q)
{
    Node *p = q.front;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }
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
    int choice;
    Queue q;

    while (true)
    {
        cin >> choice;
        int num;
        if (choice == 4)
            break;

        else if (choice == 1)
        {
            cin >> num;
            cout << "pushed \n";
            EnQueue(q, num);
        }

        else if (choice == 2)
        {
            if (isEmpty(q))
                cout << "EMPTY \n";
            else
                cout << Front(q) << "\n";

            DeQueue(q);
        }

        else if (choice == 3)
        {
            if (isEmpty(q))
                cout << "EMPTY \n";
            
            else
                cout << Front(q) << "\n";
        }

        cout << "QUEUE: ";
        Duyet(q);
        cout << "\n";
    }

    return 0;
}