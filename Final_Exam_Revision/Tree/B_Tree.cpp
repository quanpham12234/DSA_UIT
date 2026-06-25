#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree_Node {
    vector<int> keys;
    vector<Tree_Node*> children;

    bool is_leaf() {
        return children.empty();
    }
};

class B_Tree {
    private:
    Tree_Node* root;
    int m; // m: Bậc

    public:
    B_Tree(int init_m) {
        if (init_m % 2 == 0) {
            init_m = init_m / 2 + 1;
        }
        this->m = init_m;
        root = nullptr;
    }

    bool empty() {
        return root == nullptr;
    }

    Tree_Node* getRoot() {
        return this->root;
    }

    pair<int, vector<Tree_Node*>> search(int data) {
        vector<Tree_Node*> path;
        Tree_Node* p = this->root;

        while (p != nullptr) {
            path.push_back(p);
            auto it = lower_bound(p->keys.begin(), p->keys.end(), data);

            if (it != p->keys.end() && *it == data) {
                return {it - p->keys.begin(), path};
            }

            else {
                p = p->children[it - p->keys.begin()];
            }
        }

        return {-1, path};
    }

    Tree_Node* split (Tree_Node* i, Tree_Node *p) {
        // B1: Kiểm tra điều kiện
        if (i->keys.size() < m)
            return nullptr;

        // B2: Tạo node mới
        Tree_Node* newNode = new Tree_Node;
        int mid_index = i->keys.size() / 2;
        int mid_val = i->keys[mid_index];

        // Chuyển các phần tử bên phải sang node mới
        newNode->keys = vector<int> (i->keys.begin() + mid_index + 1, i->keys.end());
        i->keys.resize(mid_index);

        // Chuyển các children của phần tử bên phải
        if (!i->is_leaf()) {
            for (int j = mid_index + 1; j < i->children.size(); j++) {
                newNode->children.push_back(i->children[j]);
            }
            i->children.resize(mid_index + 1);
        }

        // B3: Xử lý phần tử cha
        if (p == nullptr) {
            p = new Tree_Node;
            p->children.push_back(i);
            p->keys.push_back(mid_val);
            p->children.push_back(newNode);
            return p;
        }

        else {
            auto it = lower_bound(p->keys.begin(), p->keys.end(), mid_val);
            int index = it - p->keys.begin();

            p->keys.insert(it, mid_val);
            p->children.insert(p->children.begin() + index + 1, newNode);

            return nullptr;
        }
    }
    
};

int main() {

}