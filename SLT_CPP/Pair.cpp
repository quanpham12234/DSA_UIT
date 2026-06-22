#include <iostream>

using namespace std;

// first, second

int main()
{
    pair<int, int> p1 = make_pair(10, 20); // p1.first = 10, p1.second = 20
    pair<int, int> p2 = {10,20};
    // pair<int, long long> p;
    // pair<char, int> p;

    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;

    return 0;
}