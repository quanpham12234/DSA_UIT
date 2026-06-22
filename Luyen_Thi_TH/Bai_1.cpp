/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

void add(Node* &root, int x){
    /*
        Hàm thêm một số vào cây
        Hàm này đã được viết đầy đủ và đảm bảo đúng
        Sinh viên không cần phải viết hàm này
    */
    if (root == NULL){
        root = new Node;
        root->val = x;
        root->left = root->right= NULL;
    } else {
        if (x < root->val) add(root->left, x);
        else if (x > root->val) add(root->right, x);
    }
}


//###INSERT CODE HERE -
int calc(Node* root, int &count) {
    if (root == nullptr) return 0;

    int left_height = calc(root->left, count);
    int right_height = calc(root->right, count);

    int diff = left_height - right_height;
    if (diff >= 2 || diff <= -2)
        count++;

    return ((left_height > right_height)? left_height: right_height) + 1;
}

int unbalance(Node* root) {
    int count = 0;
    int ans = calc(root, count);

    return count;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node *root = NULL;

    int x;
    while (cin >> x){
        add(root, x);
    }
    
    cout << "So node bi mat can bang la " << unbalance(root);
    return 0;
}