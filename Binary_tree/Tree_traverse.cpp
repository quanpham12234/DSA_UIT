#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

void Inorder_Traverse(TreeNode *root, vector<int> &result) // Left -> Root -> Right
{
    if (root == nullptr)
        return;

    Inorder_Traverse(root->left, result); // Left

    result.push_back(root->val);

    Inorder_Traverse(root->right, result); // Right
}

void Preorder_Traverse(TreeNode *root, vector<int> &result) // Root -> Left -> Right
{
    if (root == nullptr)
        return;
    result.push_back(root->val);

    Preorder_Traverse(root->left, result);

    Preorder_Traverse(root->right, result);
}

void Postorder_Traverse(TreeNode *root, vector<int> &result) // Left -> Right -> Root
{
    if (root == nullptr)
        return;

    Postorder_Traverse(root->left, result);

    Postorder_Traverse(root->right, result);

    result.push_back(root->val);
}

int TreeSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return root->val + TreeSum(root->left) + TreeSum(root->right);
}

int TreeSum_2(TreeNode *root)
{
    queue<TreeNode *> q;
    int sum = 0;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        sum += current->val;
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
    return sum;
}

int Tree_Min(TreeNode *root) // Stack (DF)
{
    int Smallest = INT_MAX;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *current = st.top();
        st.pop();
        if (current->val < Smallest)
            Smallest = current->val;

        if (current->right != nullptr)
            st.push(current->right);
        if (current->left != nullptr)
            st.push(current->left);
    }

    return Smallest;
}

int Tree_Min2(TreeNode *root) // Queue (BF)
{
    queue<TreeNode *> q;
    q.push(root);
    int Smallest = INT_MAX;

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current->val < Smallest)
            Smallest = current->val;

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
    return Smallest;
}

int Tree_Min3(TreeNode *root) // Recursion
{
    if (root == nullptr)
        return INT_MAX;
    int left = Tree_Min3(root->left);
    int right = Tree_Min3(root->right);
    return min(left, min(right, root->val));
}

int MaxPathSum(TreeNode *root)
{
    if (root == nullptr)
    return 0;
    int left = MaxPathSum(root->left);
    int right = MaxPathSum(root->right);
    return root->val + max(left,right);
}

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    vector<int> Inorder;
    vector<int> Preorder;
    vector<int> Postorder;
    Inorder_Traverse(a, Inorder);     // Left -> Root -> Right
    Preorder_Traverse(a, Preorder);   // Root -> Left -> Right
    Postorder_Traverse(a, Postorder); // Left -> Right -> Root

    //     1
    //    / \
    //   2   3
    //  / \   \
    // 4   5   6

    for (int x : Inorder)
        cout << x << " ";
    cout << endl;

    for (int x : Preorder)
        cout << x << " ";
    cout << endl;

    for (int x : Postorder)
        cout << x << " ";
    cout << endl;

    cout << "Tree Sum1: " << TreeSum(a) << endl;
    cout << "Tree Sum2: " << TreeSum_2(a) << endl;

    cout << "Smallest Number: " << Tree_Min(a) << endl;
    cout << "Smallest Number2: " << Tree_Min2(a) << endl;
    cout << "Smallest Number3: " << Tree_Min3(a) << endl;

    cout << "MaxRootToLeafPath: " << MaxPathSum(a) << endl;

    return 0;
}