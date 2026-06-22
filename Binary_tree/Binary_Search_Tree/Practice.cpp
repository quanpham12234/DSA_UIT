#include <iostream>
#include <algorithm>

using namespace std;

struct Tree_Node
{
    int val;
    Tree_Node *left = nullptr;
    Tree_Node *right = nullptr;
};

Tree_Node *Create_Node(int x)
{
    Tree_Node *Node = new Tree_Node;
    Node->val = x;
    Node->left = nullptr;
    Node->right = nullptr;

    return Node;
}

class Binary_Search_Tree
{
private:
    Tree_Node *root = nullptr;

    Tree_Node *Min_Value_Node(Tree_Node *root)
    {
        Tree_Node *cur = root;
        while (cur != nullptr && cur->left != nullptr)
        {
            cur = cur->left;
        }

        return cur;
    }

    Tree_Node *deleteNodeRec(Tree_Node *root, int x)
    {
        if (root == nullptr)
            return root;

        if (x < root->val)
            root->left = deleteNodeRec(root->left, x);

        else if (x > root->val)
            root->right = deleteNodeRec(root->right, x);

        else
        {
            if (root->left == nullptr)
            {
                Tree_Node *temp = root->left;
                delete root->left;
                return temp;
            }

            else if (root->right == nullptr)
            {
                Tree_Node *temp = root->right;
                delete root->right;
                return temp;
            }

            else
            {
                Tree_Node *temp = Min_Value_Node(root->right);
                root->val = temp->val;
                root->right = deleteNodeRec(root->right, temp->val);
            }
        }

        return root;
    }

public:
    void insert(int x)
    {
        Tree_Node *p = Create_Node(x);
        if (root == nullptr)
        {
            root = p;
            return;
        }

        Tree_Node *q = root;
        Tree_Node *prev = nullptr;
        while (q != nullptr)
        {
            if (q->val == x)
            {
                delete q;
                return;
            }

            else if (q->val > x)
            {
                prev = q;
                q = q->left;
            }

            else
            {
                prev = q;
                q = q->right;
            }
        }

        if (prev->val > x)
            prev->left = p;

        else
            prev->right = p;
    }

    bool search(int x)
    {
        Tree_Node *p = root;

        while (p != nullptr)
        {
            if (p->val == x)
            {
                return true;
            }

            else if (p->val > x)
                p = p->left;

            else
                p = p->right;
        }
        return false;
    }

    void inorder_traversal(Tree_Node *root)
    {
        if (root == nullptr)
            return;

        inorder_traversal(root->left);
        cout << root->val << " ";
        inorder_traversal(root->right);
    }

    Tree_Node *getRoot()
    {
        return root;
    }

    int countNodes(Tree_Node *root)
    {
        if (root == nullptr)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int height(Tree_Node *root)
    {
        if (root == nullptr)
            return 0;

        return max(height(root->left), height(root->right)) + 1;
    }

    void deleteNode(int x)
    {
        root = deleteNodeRec(root, x);
    }
};

bool isValidBST(Tree_Node *root)
{
}

int main()
{
    Binary_Search_Tree bst;

    cout << "=== 1. TEST THEM NODE (INSERT) ===\n";
    // Tạo một cây có cấu trúc đầy đủ các trường hợpF
    int arr[] = {50, 30, 70, 20, 40, 60, 80, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        bst.insert(arr[i]);
    }
    cout << "- Inorder (mong doi: 20 30 40 45 50 60 70 80): \n  -> Thuc te: ";
    bst.inorder_traversal(bst.getRoot());
    cout << "\n\n";

    cout << "=== 2. TEST THONG KE CAY ===\n";
    cout << "- So luong node (mong doi: 8): " << bst.countNodes(bst.getRoot()) << "\n";
    cout << "- Chieu cao cay (mong doi: 4): " << bst.height(bst.getRoot()) << "\n\n";

    cout << "=== 3. TEST TIM KIEM (SEARCH) ===\n";
    cout << "- Tim so 45: " << (bst.search(45) ? "Ton tai" : "Khong ton tai") << "\n";
    cout << "- Tim so 99: " << (bst.search(99) ? "Ton tai" : "Khong ton tai") << "\n\n";

    cout << "=== 4. TEST XOA NODE (DELETE) ===\n";

    // TH1: Xóa Node lá
    cout << "[TH1] Xoa node 20 (Node la)\n";
    bst.deleteNode(20);
    cout << "  -> Ket qua: ";
    bst.inorder_traversal(bst.getRoot());
    cout << "\n";

    // TH2: Xóa Node có 1 con
    cout << "[TH2] Xoa node 40 (Co 1 con phai la 45)\n";
    bst.deleteNode(40);
    cout << "  -> Ket qua: ";
    bst.inorder_traversal(bst.getRoot());
    cout << "\n";

    // TH3: Xóa Node có 2 con (Gốc)
    cout << "[TH3] Xoa node 50 (Node goc, co 2 con)\n";
    bst.deleteNode(50);
    cout << "  -> Ket qua: ";
    bst.inorder_traversal(bst.getRoot());
    cout << "\n\n";

    cout << "=== 5. THONG KE LAI SAU KHI XOA ===\n";
    cout << "- So luong node con lai: " << bst.countNodes(bst.getRoot()) << "\n";

    return 0;
}