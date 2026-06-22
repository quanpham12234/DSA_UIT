/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

struct Node_Tree
{
    int val;
    Node_Tree *left;
    Node_Tree *right;
};

Node_Tree *CreateNode(int key)
{
    Node_Tree *newNode = new Node_Tree;
    newNode->val = key;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

class Binary_Search_Tree
{
private:
    Node_Tree *root;

public:
    Binary_Search_Tree()
    {
        root = nullptr;
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    void insert(int key)
    {
        if (isEmpty())
        {
            root = CreateNode(key);
            return;
        }

        Node_Tree *q = root;
        Node_Tree *prev = nullptr;
        while (q != nullptr)
        {
            if (q->val == key)
            {
                return;
            }

            else if (key > q->val)
            {
                prev = q;
                q = q->right;
            }

            else
            {
                prev = q;
                q = q->left;
            }
        }

        Node_Tree* p = CreateNode(key);
        if (key > prev->val)
        {
            prev->right = p;
        }

        else
            prev->left = p;
    }

    Node_Tree *getRoot()
    {
        return root;
    }
};

int count_1_children(Node_Tree *root)
{
    if (root == nullptr)
        return 0;

    if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr))
        return 1 + count_1_children(root->left) + count_1_children(root->right);

    else
    return 0 + count_1_children(root->left) + count_1_children(root->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Binary_Search_Tree bst;
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        bst.insert(n);
    }

    cout << count_1_children(bst.getRoot());
}