#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char val;
    Node* left;
    Node* right;

    Node(char v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

void dfv_helper (Node *root, vector<char> &result){
    if (root == nullptr) return;

    result.push_back(root->val);
    dfv_helper(root->left,result);
    dfv_helper(root->right,result);
}

vector<char> dfv(Node *root){
    vector<char> result;
    dfv_helper(root,result);
    return result;
}

void deleteTree(Node *root){
    if (root == nullptr) return;
    
    deleteTree(root->left);
    deleteTree(root->right);

    delete(root);
}

int main(){
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

    vector<char> temp = dfv(a);
    for (char x : temp)
    cout << x << endl;

    deleteTree(a);
    return 0;

}