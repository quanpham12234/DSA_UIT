#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;
// O(logn)
// insert
// size
// find
// count
// Erase
// VD : Dem so phan tu khac nhau
// multiset <datatype> name;
// Cho mang n phan tu va so nguyen k, doi voi moi day con lien tiep co chieu k
// In ra duoc phan tu lon nhat trong day con do
// unordered_set , O(1) -> O(n)
int main()
{
    unordered_set<int> s;
    for (int i =0 ; i < 10 ;i++)
    s.insert(i);
    for (int i : s)
    {
        cout << i << " ";
    }
    return 0;
}