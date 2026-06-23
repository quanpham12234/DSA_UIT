#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct Stack
{
    Node *head;
};

void Create_Stack(Stack &st)
{
    st.head = nullptr;
}

Node *CreateNode(int x)
{
    Node *newNode = new Node();
    newNode->val = x;
    newNode->next = nullptr;

    return newNode;
}

void push(Stack &st, int n)
{
    Node *p = CreateNode(n);

    p->next = st.head;
    st.head = p;
}

void pop(Stack &st)
{
    Node *p = st.head;
    st.head = p->next;
    delete p;
}

int top(const Stack &st)
{
    return st.head->val;
}

bool empty(const Stack &st)
{
    return st.head == nullptr;
}

void traverse(const Stack& st) {
    Node* p = st.head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int choice;
    Stack st;
    Create_Stack(st);

    while (true)
    {
        cin >> choice;
        if (choice == 4)
            break;

        else if (choice == 1)
        {
            int n;
            cin >> n;
            push(st, n);
            cout << "pushed \n";
        }

        else if (choice == 2)
        {
            if (!empty(st))
            {
                cout << top(st) << "\n";
                pop(st);
            }

            else
                cout << "EMPTY \n";
        }

        else
        {
            if (!empty(st))
            {
                cout << top(st) << "\n";
            }

            else
                cout << "EMPTY \n";
        }

        cout << "STACK: ";
        traverse(st);
        cout << "\n";
    }

    return 0;
}