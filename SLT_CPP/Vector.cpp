#include <iostream>
#include <vector>

using namespace std;

// push_back()
// size()
// begin()
// end()
// front()
// end()
// insert()
// erase()
// assign()

int main()
{
    vector<int> v(3, 100); // {100, 100, 100}
    v.push_back(3);        // {100, 100, 100, 3}
    v.push_back(2);        // {100, 100, 100, 3, 2}
    v.push_back(1);        // {100, 100, 100, 3, 2, 1}
    v.push_back(5);        // {100, 100, 100, 3, 2, 1, 5}

    cout << v.size() << endl; // size = 4
    cout << v[2] << endl;     // v[2] = 100

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    int n;
    cin >> n;
    vector<int> v2(n);
    for (int i = 0; i < n; i++)
        cin >> v2[i];

    // Hoặc dùng push_back để bỏ thêm vào, không cần phải khai báo số lượng phần tử trong vector

    v.insert(v.begin() + 4, 100); // Complexity: O(N) - Hạn chế dùng
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    v.erase(v.begin() + 4);
    for (int x : v)
        cout << x << " ";
    cout << endl;

    return 0;
}
