#include <iostream>
#include <set>

using namespace std;

// insert(): O(LogN)

int main()
{
    set<int> se;  //
    se.insert(1); // 1
    se.insert(3); // 1 3
    se.insert(2); // 1 2 3
    se.insert(2); // 1 2 3
    se.insert(3); // 1 2 3
    se.insert(4); // 1 2 3 4

    cout << se.size() << endl; // size = 4

    for (int x : se)
        cout << x << " "; 

    return 0;
}