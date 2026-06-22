/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNode
{
    int key;
    TNode *pLeft;
    TNode *pRight;
};

struct Tree
{
    TNode *root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode *CreateTNode(int x)
{
    TNode *p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
bool isBrother(Tree, int, int);

void run(int q, Tree T)
{
    // ###INSERT CODE HERE -
    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << a << " va " << b;
        if (isBrother(T, a, b))
        {
            cout << " la anh em \n";
        }
        else
            cout << " khong phai la anh em \n";
    }
}

void Insert(Tree &tree, int x)
{
    TNode *p = tree.root;
    TNode *prev = nullptr;
    TNode *q = CreateTNode(x);

    if (p == nullptr)
    {
        tree.root = q;
        return;
    }
    while (p != nullptr)
    {
        if (p->key == x)
        {
            delete q;
            return;
        }

        if (x > p->key)
        {
            prev = p;
            p = p->pRight;
        }

        else
        {
            prev = p;
            p = p->pLeft;
        }
    }

    if (x > prev->key)
    {
        prev->pRight = q;
    }

    else
        prev->pLeft = q;
}

bool isBrother(Tree t, int a, int b)
{
    TNode *p = t.root;

    while (p != nullptr)
    {
        if (p->pLeft != nullptr && p->pRight != nullptr)
        {
            if ((p->pLeft->key == a && p->pRight->key == b) || (p->pLeft->key == b && p->pRight->key == a))
                return true;

            if (a < p->key && b < p->key)
                p = p->pLeft;

            else if (a > p->key && b > p->key)
                p = p->pRight;

            else
                return false;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n;
    cin >> n;
    int data;
    while (n != 0)
    {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q;
    cin >> q;
    run(q, T);

    return 0;
}
