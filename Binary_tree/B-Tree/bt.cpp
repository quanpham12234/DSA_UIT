/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
struct Tree_Node
{
    int val;
    int height;
    Tree_Node *left = nullptr;
    Tree_Node *right = nullptr;
};

struct Binary_Search_Tree
{
    Tree_Node *root = nullptr;
};

Tree_Node *CreateNode(int x)
{
    Tree_Node *newNode = new Tree_Node;
    newNode->val = x;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

int getHeight(Tree_Node *n) {
    if (n == nullptr) return 0;
    return n->height;
}

int getBalance(Tree_Node *n) {
    if (n == nullptr) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

void insert(Tree_Node *&root, int x)
{
    Tree_Node *p = root;
    Tree_Node *prev = nullptr;
    Tree_Node *q = CreateNode(x);

    if (p == nullptr)
    {
        root = q;
        return;
    }

    while (p != nullptr)
    {
        if (p->val == x)
        {
            delete q;
            return;
        }

        if (x > p->val)
        {
            prev = p;
            p = p->right;
        }

        else
        {
            prev = p;
            p = p->left;
        }
    }

    if (x > prev->val)
        prev->right = q;

    else
        prev->left = q;
}

Tree_Node *MinNode(Tree_Node *root)
{
    if (root == nullptr)
        return nullptr;
    Tree_Node *p = root;

    while (p->left != nullptr)
    {
        p = p->left;
    }

    return p;
}

Tree_Node *lower_bound(Tree_Node *root, int x)
{
    if (root == nullptr)
        return nullptr;

    Tree_Node *result = nullptr;
    Tree_Node *p = root;

    while (p != nullptr)
    {
        if (x > p->val)
        {
            result = p;
            p = p->right;
        }

        else
        {
            p = p->left;
        }
    }

    return result;
}

Tree_Node *upper_bound(Tree_Node *root, int x)
{
    if (root == nullptr)
        return nullptr;

    Tree_Node *result = nullptr;
    Tree_Node *p = root;

    while (p != nullptr) {
        if (x < p->val) {
            result = p;
            p = p->left;
        }

        else p = p->right;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Binary_Search_Tree bst;

    int choice;
    while (true)
    {
        cin >> choice;
        int n;

        if (choice == 0)
            break;

        else if (choice == 1)
        {
            cin >> n;
            insert(bst.root, n);
        }

        else if (choice == 2)
        {
            cin >> n;
            Tree_Node *result = lower_bound(bst.root, n);
            if (result == nullptr)
                cout << "NULL";
            else
                cout << result->val;

            cout << "\n";
        }

        else
        {
            cin >> n;
            Tree_Node *result = upper_bound(bst.root, n);
            if (result == nullptr)
                cout << "NULL";
            else
                cout << result->val;

            cout << "\n";
        }
    }

    return 0;
}