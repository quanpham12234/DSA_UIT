#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *Create_Node(int x)
{
    Node *New_Node = new Node;
    New_Node->data = x;
    New_Node->next = nullptr;

    return New_Node;
}

void push_front(List &l, int x)
{
    Node *a = Create_Node(x);
    if (l.head == nullptr)
    {
        l.head = a;
        l.tail = a;
    }

    else
    {
        a->next = l.head;
        l.head = a;
    }
}

void push_back(List &l, int x)
{
    Node *a = Create_Node(x);
    if (l.head == nullptr)
    {
        l.head = a;
        l.tail = a;
    }

    else
    {
        l.tail->next = a;
        l.tail = a;
    }
}

void Insert_Node_After_Q(List &l, int x, Node *q)
{
    Node *a = Create_Node(x);
    if (q == nullptr)
    {
        push_back(l, x);
    }

    else
    {
        a->next = q->next;
        q->next = a;

        if (l.tail == q)
            l.tail = a;
    }
}

void pop_front(List &l)
{
    Node *p = l.head;

    if (p == nullptr)
        return;

    l.head = p->next;

    if (l.head == nullptr)
        l.tail = nullptr;

    delete p;
}

void pop_back(List &l)
{
    if (l.head == nullptr)
        return;

    else if (l.head == l.tail)
    {
        delete l.head;
        l.head = l.tail = nullptr;
    }

    else
    {
        Node *prev = l.head;
        while (prev->next != l.tail && prev != nullptr)
        {
            prev = prev->next;
        }

        delete l.tail;
        prev->next = nullptr;
        l.tail = prev;
        l.tail->next = nullptr;
    }
}

void Erase_Node_After_Q(List &l, Node *q)
{
    if (q == nullptr || q->next == nullptr)
        return;

    Node *temp = q->next;

    q->next = temp->next;
    delete temp;

    if (q->next == nullptr)
        l.tail = q;
}

void print_list(List &l)
{
    Node *p = l.head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

void Selection_Sort(List &l)
{
    Node *p = l.head;

    while (p != nullptr)
    {
        Node *q = p->next;
        Node *Min = p;

        while (q != nullptr)
        {
            if (q->data < Min->data)
                Min = q;

            q = q->next;
        }
        swap(p->data, Min->data);
        p = p->next;
    }
}

int main()
{
    List l;
    push_back(l, 5);
    push_back(l, -4);
    push_back(l, 1);
    push_back(l, 2);
    push_back(l, 10);
    push_back(l, 8);
    push_back(l, 5);

    print_list(l);

    Selection_Sort(l);
    print_list(l);

    pop_back(l);
    print_list(l);

    pop_front(l);
    print_list(l);

    return 0;
}