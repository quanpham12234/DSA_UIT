#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

// (key, value)
// insert
// find
// count
// Dem so lan xuat hien cua cac phan tu trong mang, sau do in ra kem theo tan suat
// 8
// 1 1 2 1 3 5 1 4
// Output
// 1 4
// 2 1
// 3 1
// 4 1
// 5 1
// 9
// java
// python
// string
// java
// python
// c++
// sql
// sql
// java
// multimap -> use insert 
// unordered_map 

int main()
{
    unordered_map<int,int> mp;
    mp.insert({1,100});
    mp.insert({2,200});
    mp.insert({1,200});
    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << (*mp.begin()).first << endl;
    
    return 0;
}
