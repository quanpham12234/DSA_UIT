#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
    int val;
    int cnt = 1;
    Node *left = nullptr;
    Node *right = nullptr;
};

Node *CreateNode(int x)
{
    Node *newNode = new Node;
    newNode->val = x;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

struct Binary_Search_Tree
{
    Node *root = nullptr;

    void inorder(Node *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void insert(int x)
    {
        Node *p = root;
        Node *prev = nullptr;

        Node *q = CreateNode(x);

        if (p == nullptr)
        {
            root = q;
            return;
        }

        while (p != nullptr)
        {
            if (p->val == x)
            {
                root->cnt++;
                delete q;
                return;
            }

            else if (x > p->val)
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

    bool search(int x)
    {
        Node *p = root;
        if (p == nullptr)
            return false;

        while (p != nullptr)
        {
            if (x == p->val)
                return true;
            else if (x > p->val)
                p = p->right;
            else
                p = p->left;
        }

        return false;
    }

    Node *Min(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr)
            return root;

        return Min(root->left);
    }

    Node *Max(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->right == nullptr)
            return root;

        return Max(root->right);
    }

    int count_Node(Node *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + count_Node(root->left) + count_Node(root->right);
    }

    int height(Node *root)
    {
        if (root == nullptr)
            return 0;

        return max(height(root->left), height(root->right)) + 1;
    }

    void deleteX(Node *&root, int x)
    {
        if (root == nullptr)
            return;

        if (x > root->val)
            deleteX(root->right, x);
        else if (x < root->val)
            deleteX(root->left, x);
        else
        {
            Node *p = root;
            if (root->left == nullptr)
            {
                root = root->right;
                delete p;
            }

            else if (root->right == nullptr)
            {
                root = root->left;
                delete p;
            }

            else
            {
                Node *q = Min(root->right);
                p->val = q->val;
                deleteX(root->right, q->val);
            }
        }
    }

    void printDistinct(Node* root) {
        if (root == nullptr) return;

        printDistinct(root->left);

        cout << "Gia tri: " << root->val << " xuat hien " << root->cnt << " lan! \n";

        printDistinct(root->right);
    } 
};

// int main()
// {
//     Binary_Search_Tree bst;

//     bst.insert(5);
//     bst.insert(3);
//     bst.insert(2);
//     bst.insert(1);
//     bst.insert(4);
//     bst.insert(6);
//     bst.insert(8);
//     bst.insert(12);
//     bst.insert(0);
//     bst.insert(29);
//     bst.insert(-5);
//     bst.insert(2);

//     bst.inorder(bst.root);

//     int n;
//     cout << "\nNhap phan tu ban muon tim kiem: ";
//     cin >> n;

//     if (bst.search(n))
//         cout << "Tim thay! \n";

//     else
//         cout << "Khong tim thay! \n";

//     Node *Min = bst.Min(bst.root);
//     Node *Max = bst.Max(bst.root);

//     cout << "Phan tu nho nhat: " << Min->val << "\n";
//     cout << "Phan tu lon nhat: " << Max->val << "\n";

//     int count = bst.count_Node(bst.root);
//     int height = bst.height(bst.root);

//     cout << "Tong cong: " << count << " (Node) \n";
//     cout << "Chieu cao: " << height << "\n";

//     cout << "Nhap so ban muon xoa: ";
//     cin >> n;

//     bst.deleteX(bst.root,n);

//     bst.inorder(bst.root);

//     return 0;
// }

int main() {
    Binary_Search_Tree bst;
    int n; cin >> n;
    vector<int> arr;

    for (int i = 0;i < n ;i++) {
        int x; cin >> x;
        arr.push_back(x);
        bst.insert(x);
    }

    int spe_count = bst.count_Node(bst.root);

    cout << "So phan tu dac biet: " << spe_count << "\n";

    bst.printDistinct(bst.root);
}