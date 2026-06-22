#include <iostream> 
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int Test_Case; cin >> Test_Case;
    while (Test_Case--)
    {
        int n; cin >> n;
        // C1:
        // set<int> result;
        // for (int i = 0; i < n; i++)
        // {
        //     int x; cin >> x;
        //     result.insert(x);
        // }
        // cout << result.size() << endl;
        
        // C2:
        // map<int,int> mp;
        // for (int i = 0; i < n ;i++)
        // {
        //     int x; cin >> x;
        //     mp[x]++;
        // }
        // cout << mp.size() << endl;

        // C3:
        // int a[n];
        // for (int i = 0; i < n ;i++)
        // cin >> a[i];
        // sort(a, a+n);
        // int count = 1;
        // for (int i = 1; i < n ;i++)
        // {
        //     if (a[i] != a[i-1])
        //     count++;
        // }
        // cout << count << endl;
    }
}