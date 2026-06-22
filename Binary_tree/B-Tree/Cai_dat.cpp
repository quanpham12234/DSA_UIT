#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node_Tree
{
    vector<int> val;
    vector<Node_Tree *> children;

    bool is_leaf()
    {
        return children.empty();
    }
};

class B_Tree
{
private:
    Node_Tree *root;
    int m; // m : bậc

public:
    B_Tree(int init_m)
    {
        if (init_m % 2 == 0)
        {
            init_m = init_m / 2 + 1;
        }
        this->m = init_m;
        root = nullptr;
    }

    bool empty()
    {
        return root == nullptr;
    }

    Node_Tree *getRoot()
    {
        return root;
    }

    pair<int, vector<Node_Tree *>> search(Node_Tree *root, int data)
    {
        vector<Node_Tree *> path;
        Node_Tree *p = root;

        while (p != nullptr)
        {
            path.push_back(p);
            auto it = lower_bound(p->val.begin(), p->val.end(), data);

            if (it != p->val.end() && *it == data)
            {
                return {it - p->val.begin(), path};
            }

            else
            {
                if (p->is_leaf())
                    break;
                p = p->children[it - p->val.begin()];
            }
        }

        return {-1, path};
    }

    // Hàm chia tách node i khi bị đầy, p là node cha của i
    Node_Tree *split(Node_Tree *i, Node_Tree *p)
    {
        // B1: Kiểm tra điều kiện
        if (i->val.size() < m)
            return nullptr;

        // B2: Tạo node mới
        Node_Tree *newNode = new Node_Tree;
        int mid_index = i->val.size() / 2;
        auto split_val = i->val[mid_index];

        // Chuyển các phần tử bên phải sang node mới
        for (int j = mid_index + 1; j < i->val.size(); j++)
        {
            newNode->val.push_back(i->val[j]);
        }

        // Chuyển các children của phần tử bên phải
        if (!i->is_leaf())
        {
            for (int j = mid_index + 1; j < i->children.size(); j++)
            {
                newNode->children.push_back(i->children[j]);
            }
            i->children.resize(mid_index + 1);
        }

        // resize phần tử bên trái
        i->val.resize(mid_index);

        // B3: Xử lý node cha
        if (p == nullptr)
        {
            p = new Node_Tree;
            p->children.push_back(i);
            p->val.push_back(split_val);
            p->children.push_back(newNode);
            return p;
        }

        else
        {
            auto it = lower_bound(p->val.begin(), p->val.end(), split_val); // find insert iterator
            int index = it - p->val.begin();                                // convert iterator -> index

            p->val.insert(it, split_val);
            p->children.insert(p->children.begin() + index + 1, newNode);

            return nullptr;
        }
    }

    void insert(int key)
    {
        // B1: Xử lý trường hợp cây rỗng
        if (root == nullptr)
        {
            root = new Node_Tree;
            root->val.push_back(key);
            return;
        }

        // B2: Dò đường tìm node lá
        pair<int, vector<Node_Tree *>> search_result = search(root, key);

        // Phần tử cần chèn đã có
        if (search_result.first != -1)
        {
            return;
        }

        vector<Node_Tree *> path = search_result.second;

        Node_Tree *Insert_Node = path.back();
        auto it = lower_bound(Insert_Node->val.begin(), Insert_Node->val.end(), key);

        Insert_Node->val.insert(it, key);

        // B3: Check split
        for (int k = path.size() - 1; k >= 0; k--)
        {
            Node_Tree *current_Node = path[k];

            if (current_Node->val.size() == m)
            {
                Node_Tree *parent = (k == 0) ? nullptr : path[k - 1];

                Node_Tree *newRoot = split(current_Node, parent);

                if (newRoot != nullptr)
                    root = newRoot;
            }

            else
            {
                break;
            }
        }
    }

    // Thêm hàm này vào phần public của class B_Tree
    void printTree(Node_Tree *root)
    {
        if (root == nullptr)
            return;
        queue<Node_Tree *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node_Tree *node = q.front();
                q.pop();
                cout << "[";
                for (size_t j = 0; j < node->val.size(); j++)
                {
                    cout << node->val[j];
                    if (j < node->val.size() - 1)
                        cout << ",";
                }
                cout << "] ";
                for (auto child : node->children)
                {
                    q.push(child);
                }
            }
            cout << endl;
        }
    }

    void print()
    {
        if (empty())
        {
            cout << "Cây đang rỗng!" << endl;
            return;
        }
        printTree(root);
        cout << "-----------------------" << endl;
    }

    Node_Tree *Predecessor(Node_Tree *root)
    {
        Node_Tree *p = root;
        while (!p->children.empty())
        {
            p = p->children.back();
        }

        return p;
    }

    Node_Tree *Successor(Node_Tree *root)
    {
        Node_Tree *p = root;
        while (!p->children.empty())
        {
            p = p->children[0];
        }

        return p;
    }

    void borrow_from_left(Node_Tree *parent, int ip)
    { // ip: Vi tri cua Node thieu khoa
        Node_Tree *node = parent->children[ip];
        Node_Tree *left_node = parent->children[ip - 1];

        // Kéo khóa của Node cha vị trí đầu tiên của Node thiếu
        node->val.insert(node->val.begin(), parent->val[ip - 1]);

        // Chuyển con cuối của Left_Sibling thành con đầu của Node thiếu (Nếu không phải node Lá)
        if (!node->children.empty())
        {
            node->children.insert(node->children.begin(), left_node->children.back());
            left_node->children.pop_back();
        }

        // Đẩy khóa cuối của Left_Sibling lên thế chỗ cha
        parent->val[ip - 1] = left_node->val.back();

        // Xóa khóa cuối của Sibling trái
        left_node->val.pop_back();
    }

    void borrow_from_right(Node_Tree *parent, int ip)
    {
        Node_Tree *node = parent->children[ip];
        Node_Tree *right_node = parent->children[ip + 1];

        node->val.push_back(parent->val[ip]);

        if (!node->children.empty())
        {
            node->children.push_back(right_node->children.front());
            right_node->children.erase(right_node->children.begin());
        }

        parent->val[ip] = right_node->val.front();

        right_node->val.erase(right_node->val.begin());
    }

    int find_cat_partner(Node_Tree *parent, int ip)
    {
        int s = parent->children[ip]->val.size();

        if (ip > 0)
        {
            int left_size = parent->children[ip - 1]->val.size();
            if (left_size + s < m - 1)
            {
                return ip - 1;
            }
        }

        if (ip < parent->children.size() - 1)
        {
            int right_size = parent->children[ip + 1]->val.size();
            if (right_size + s < m - 1)
            {
                return ip;
            }
        }

        return -1;
    }

    void merge(Node_Tree *parent, int left_index)
    {
        // Xác định 2 Node sẽ được gộp
        Node_Tree *left_node = parent->children[left_index];
        Node_Tree *right_node = parent->children[left_index + 1];

        // Kéo khóa của Cha (Vách ngăn) xuống cuối Node Trái
        left_node->val.push_back(parent->val[left_index]);

        // Gom toàn bộ khóa của Node phải sang bên trái
        left_node->val.insert(left_node->val.end(), right_node->val.begin(), right_node->val.end());

        // Gom toàn bộ Node con của Node phải sang bên trái
        if (!left_node->children.empty())
            left_node->children.insert(left_node->children.end(), right_node->children.begin(), right_node->children.end());

        // Cập nhật lại node cha
        parent->val.erase(parent->val.begin() + left_index);

        // Xoá con trỏ tới node phải
        parent->children.erase(parent->children.begin() + left_index + 1);

        delete right_node;
    }

    void fix_child_underflow(Node_Tree *parent, int ip, int m)
    {
        int min_keys = (m - 1) / 2;

        if (parent->children[ip]->val.size() >= min_keys)
        {
            return;
        }

        // Mượn ae trái
        if (ip > 0 && parent->children[ip - 1]->val.size() >= min_keys)
            borrow_from_left(parent, ip);

        // Mượn ae phải
        else if (ip < parent->children.size() - 1 && parent->children[ip + 1]->val.size() >= min_keys)
            borrow_from_right(parent, ip);

        // Gộp
        else
        {
            int left_index = find_cat_partner(parent, ip);
            if (left_index != -1)
            {
                merge(parent, left_index);
            }
        }
    }

    void delete_key(Node_Tree *node, int key, int m)
    {
        int min_keys = (m + 1) / 2 - 1;

        // Tìm vị trí của khóa trong mảng val
        int i = 0;
        while (i < node->val.size() && node->val[i] < key)
        {
            i++;
        }

        // --- TRƯỜNG HỢP A: TÌM THẤY KHÓA Ở NODE HIỆN TẠI ---
        if (i < node->val.size() && node->val[i] == key)
        {

            // TH 1: Nó là Node Lá -> Xóa trực tiếp
            if (node->children.empty())
            {
                node->val.erase(node->val.begin() + i);
            }
            // TH 2: Nó là Node Trong -> Tìm người đóng thế
            else
            {
                Node_Tree *left_child = node->children[i];
                Node_Tree *right_child = node->children[i + 1];

                // TH 2.1: Nhánh trái dư giả -> Đổi chỗ với Predecessor
                if (left_child->val.size() > min_keys)
                {
                    Node_Tree *pred_node = Predecessor(left_child);
                    int pred_key = pred_node->val.back();
                    node->val[i] = pred_key;             // Copy đè lên
                    delete_key(left_child, pred_key, m); // Đi xuống xóa Predecessor
                    fix_child_underflow(node, i, m);     // Dọn dẹp underflow nếu có
                }
                // TH 2.2: Nhánh phải dư giả -> Đổi chỗ với Successor
                else if (right_child->val.size() > min_keys)
                {
                    Node_Tree *succ_node = Successor(right_child);
                    int succ_key = succ_node->val.front();
                    node->val[i] = succ_key;
                    delete_key(right_child, succ_key, m);
                    fix_child_underflow(node, i + 1, m);
                }
                // TH 2.3: Cả hai nhánh đều nghèo -> Gộp thành 1 rồi xóa
                else
                {
                    merge(node, i); // Gộp left_child, khóa i và right_child
                    // Lúc này khóa cần xóa đã nằm trong left_child (tại children[i])
                    delete_key(node->children[i], key, m);
                    fix_child_underflow(node, i, m);
                }
            }
        }
        // --- TRƯỜNG HỢP B: KHÓA NẰM Ở NHÁNH CON BÊN DƯỚI ---
        else
        {
            // Đã chạm đáy (Lá) mà vẫn không thấy -> Khóa không tồn tại
            if (node->children.empty())
            {
                return;
            }

            // Đi xuống nhánh con tương ứng để tìm và xóa
            delete_key(node->children[i], key, m);

            // Khi quay trở lên, kiểm tra xem đứa con mình vừa đi xuống có bị thiếu khóa không
            fix_child_underflow(node, i, m);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    B_Tree b_tree(m);

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
            b_tree.insert(n);
        }

        else if (choice == 2)
        {
            cin >> n;
            b_tree.delete_key(b_tree.getRoot(), n, m);
        }

        b_tree.print();
    }

    return 0;
}