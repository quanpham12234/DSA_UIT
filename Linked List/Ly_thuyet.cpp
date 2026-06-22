#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next = nullptr;
};


Node *Make_Node(int x) // Mỗi node trong dslk là 1 con trỏ 
{
    Node* NewNode = new Node;
    NewNode->val = x;
    NewNode->next = nullptr;

    return NewNode;
}

void Duyet(Node *head) {
    while (head == nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

int count(Node *head)
{
    int cnt = 0;
    while (head != nullptr)
    {
        cnt++;
        head = head->next;
    }

    return cnt;
}

void Push_Front(Node **head, int x)
{
    Node *new_node = Make_Node(x);
    new_node->next = *head;
    *head = new_node;
}

void Push_Front2(Node *&head, int x)
{
    Node *new_node = Make_Node(x);
    new_node->next = head;
    head = new_node;
}

int main()
{
    Node *node = nullptr;

    for (int i =1 ;i <= 5;i++)
    {
        Push_Front2(node,i);
    }

    Duyet(node);
}