/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
struct Node {
    int val;
    Node* left;
    Node* right;
    int x;
    int y;
};

Node* createNode(int val) {
    Node* p = new Node;
    p->val = val;
    p->left = nullptr;
    p->right = nullptr;
    p->x = 0;
    p->y = 0;
    return p;
}

void insertNode(Node*& root, int val) {
    if (!root) {
        root = createNode(val);
        return;
    }
    Node* p = root;
    Node* parent = nullptr;
    while (p) {
        parent = p;
        if (val < p->val) p = p->left;
        else if (val > p->val) p = p->right;
        else return;
    }
    if (val < parent->val) parent->left = createNode(val);
    else parent->right = createNode(val);
}

int getMaxVal(Node* root) {
    if (!root) return 0;
    while (root->right) root = root->right;
    return root->val;
}

int getWidth(int val) {
    if (val == 0) return 1;
    int w = 0;
    if (val < 0) {
        w++;
        val = -val;
    }
    while (val > 0) {
        w++;
        val /= 10;
    }
    return w;
}

int getDepth(Node* root) {
    if (!root) return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);
    return 1 + (l > r ? l : r);
}

void assignCoordinates(Node* root, int depth, int& colCounter) {
    if (!root) return;
    assignCoordinates(root->left, depth + 1, colCounter);
    
    root->x = colCounter++;
    root->y = depth;
    
    assignCoordinates(root->right, depth + 1, colCounter);
}

void putNumber(char* dest, int val, int width) {
    int temp = val;
    if (val < 0) val = -val;
    for (int i = width - 1; i >= 0; --i) {
        if (i == 0 && temp < 0) {
            dest[i] = '-';
        } else {
            dest[i] = (val % 10) + '0';
            val /= 10;
        }
    }
}

void putDots(char* dest, int width) {
    for (int i = 0; i < width; ++i) {
        dest[i] = '.';
    }
}

void buildGrid(Node* root, char** grid, int W) {
    if (!root) return;

    putNumber(&grid[root->y][root->x * W], root->val, W);

    if (root->left) {
        for (int i = root->left->x + 1; i < root->x; ++i) {
            putDots(&grid[root->y][i * W], W);
        }
    }
    
    if (root->right) {
        for (int i = root->x + 1; i < root->right->x; ++i) {
            putDots(&grid[root->y][i * W], W);
        }
    }

    buildGrid(root->left, grid, W);
    buildGrid(root->right, grid, W);
}

int main() {
    Node* root = nullptr;
    int n;
    
    while (cin >> n && n != 0) {
        insertNode(root, n);
    }

    if (!root) return 0;

    int maxVal = getMaxVal(root);
    int W = getWidth(maxVal);
    int H = getDepth(root);
    int N = 0;
    
    assignCoordinates(root, 0, N);

    char** grid = new char*[H];
    for (int i = 0; i < H; ++i) {
        grid[i] = new char[N * W + 1];
        for (int j = 0; j < N * W; ++j) {
            grid[i][j] = ' ';
        }
        grid[i][N * W] = '\0';
    }

    buildGrid(root, grid, W);

    for (int i = 0; i < H; ++i) {
        int lastChar = N * W - 1;
        while (lastChar >= 0 && grid[i][lastChar] == ' ') {
            grid[i][lastChar] = '\0';
            lastChar--;
        }
        if (grid[i][0] != '\0') {
            cout << grid[i] << "\n";
        } else {
            cout << "\n";
        }
    }

    for (int i = 0; i < H; ++i) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}