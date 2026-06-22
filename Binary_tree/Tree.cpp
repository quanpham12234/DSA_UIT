#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char val;
    Node *left;
    Node *right;

    Node(char v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

vector<char> DepthFirstValue(Node *Root)
{
    if (Root == nullptr)
        return {};
    stack<Node *> st;
    st.push(Root);
    vector<char> result;

    while (!st.empty())
    {
        Node *current = st.top();
        st.pop();

        result.push_back(current->val);

        if (current->right != nullptr)
            st.push(current->right);

        if (current->left != nullptr)
            st.push(current->left);
    }

    return result;
}

vector<char> BreadthFirstValue(Node *Root)
{
    if (Root == nullptr)
        return {};
    queue<Node *> q;
    q.push(Root);
    vector<char> result;

    while (!q.empty())
    {
        Node *Current = q.front();
        q.pop();
        result.push_back(Current->val);
        if (Current->left != nullptr)
            q.push(Current->left);
        if (Current->right != nullptr)
            q.push(Current->right);
    }
    return result;
}

bool TreeInclude(Node *Root, char Target)
{
    if (Root == nullptr) return false;
    queue<Node *> q;
    q.push(Root);
    while (!q.empty())
    {
        Node *Current = q.front();
        q.pop();
        if (Target == Current->val)
            return true;
        if (Current->left != nullptr)
            q.push(Current->left);
        if (Current->right != nullptr)
            q.push(Current->right);
    }
    return false;
}

bool TreeInclude2(Node *Root, char Target) // recursion 
{
    if (Root == nullptr) return false;
    if (Root->val == Target) return true                                                                                                                                                                                                                                                                                  ;
    return (TreeInclude2(Root->left,Target) || TreeInclude2(Root->right, Target));
}

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete (root);
}

int main()
{
    Node *a = new Node('a');
    Node *b = new Node('b');
    Node *c = new Node('c');
    Node *d = new Node('d');
    Node *e = new Node('e');
    Node *f = new Node('f');

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    vector<char> tempA = DepthFirstValue(a);
    for (char x : tempA)
        cout << x << endl;

    vector<char> tempB = BreadthFirstValue(a);
    for (char x : tempB)
        cout << x << " ";

    cout << endl;

    char KiTu;
    cout << "Nhap ki tu can tim: ";
    cin >> KiTu;

    cout << "Ket qua can tim: " << TreeInclude2(a,KiTu);

    deleteTree(a);

    //      a
    //     / \
    //    b   c
    //   / \   \
    //  d   e   f
}