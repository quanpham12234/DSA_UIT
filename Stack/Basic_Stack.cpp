#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct Stack
{
    Node *head = nullptr;
};

Node *CreateNode(int x)
{
    Node *newNode = new Node;
    newNode->val = x;
    newNode->next = nullptr;

    return newNode;
}

bool isEmpty(const Stack &st)
{
    return st.head == nullptr;
}

void Duyet(Node *head)
{
    Node *p = head;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }
}

void push(Stack &st, int x)
{
    Node *p = CreateNode(x);
    p->next = st.head;
    st.head = p;
}

void pop(Stack &st)
{
    if (isEmpty(st))
        return;

    Node *p = st.head;
    st.head = p->next;
    delete p;
}

int top(Stack &st)
{
    if (isEmpty(st) == false)
        return st.head->val;

    return -1;
}

int main()
{
    int choice;
    Stack st;
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
            push(st, num);
        }

        else if (choice == 2)
        {
            if (isEmpty(st) == true)
                cout << "EMPTY \n";

            else
                cout << top(st) << "\n";

            pop(st);
        }

        else if (choice == 3)
        {
            if (isEmpty(st) == true)
                cout << "EMPTY \n";

            else
                cout << top(st) << "\n";
        }

        cout << "STACK: ";
        Duyet(st.head);
        cout << "\n";
    }
}