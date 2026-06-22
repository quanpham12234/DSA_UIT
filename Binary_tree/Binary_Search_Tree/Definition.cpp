#include <iostream>
#include <vector>
using namespace std;

struct Tree_Node
{
    Tree_Node *Left = nullptr;
    Tree_Node *Right = nullptr;
    int val;
};

Tree_Node *Create_Tree_Node(int x)
{
    Tree_Node *newNode = new Tree_Node;
    newNode->val = x;
    newNode->Left = nullptr;
    newNode->Right = nullptr;

    return newNode;
};

struct Binary_Search_Tree
{
    Tree_Node *Root = nullptr;

    void Insert_Tree(int key)
    {
        Tree_Node *p = Create_Tree_Node(key);
        if (Root == nullptr)
        {
            Root = p;
            return;
        }

        Tree_Node *q = Root;
        Tree_Node *parent = nullptr;

        while (q != nullptr)
        {
            if (q->val > key)
            {
                parent = q;
                q = q->Left;
            }
            else if (q->val < key)
            {
                parent = q;
                q = q->Right;
            }
            else
            {
                delete p;
                return;
            }
        }
        if (parent->val > key)
            parent->Left = p;
        else
            parent->Right = p;
    }

    void Inorder_Traversal(Tree_Node *node)
    {
        if (node != nullptr)
        {
            Inorder_Traversal(node->Left);
            cout << node->val << " ";
            Inorder_Traversal(node->Right);
        }
    }

    void Print_Binary_Tree (Tree_Node* Node, vector<int> &path) {
        if (Node == nullptr) return;

        path.push_back(0);
        Print_Binary_Tree(Node->Left,path);
        path.pop_back();

        int depth = path.size();
        for (int i = 0;i < depth - 1; i++) {
            if (path[i] != path[i+1])
                cout << "|   ";

            else
                cout << "    ";
        }

        if (depth > 0)
            cout << "|---";

        cout << Node->val << "\n";
        
        path.push_back(1);
        Print_Binary_Tree(Node->Right,path);
        path.pop_back();
    }

    void Print() {
        vector<int> path;
        Print_Binary_Tree(Root, path);
    }
};

int main()
{
    Binary_Search_Tree bst;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        bst.Insert_Tree(n);
    }

    bst.Print();

    return 0;
}