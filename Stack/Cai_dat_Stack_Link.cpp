#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next = nullptr;
};

struct Stack // top : head
{
    Node *head = nullptr;
};

Node* CreateNode(int x) {
    Node* newNode = new Node;
    newNode->val = x;
    newNode->next = nullptr;

    return newNode;
}

bool isEmpty(const Stack &st)
{
    return st.head == nullptr;
}

void push(Stack &st, int x) { // Thêm vào đầu
    Node *p = CreateNode(x);
    p->next = st.head;
    st.head = p;
}

void pop(Stack &st) {
    if (isEmpty(st)) return;
    Node *p = st.head;
    st.head = p->next;

    delete p;
}

int top(const Stack& st) {
    if (isEmpty(st)) {
        cout << "Stack dang rong! \n";
        return -1; 
    }

    return st.head->val;

}