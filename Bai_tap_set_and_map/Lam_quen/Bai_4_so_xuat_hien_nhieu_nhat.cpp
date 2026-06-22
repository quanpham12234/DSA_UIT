#include <iostream>
#include <map>
using namespace std;

int main()
{
    int Test_case;
    cin >> Test_case;
    while (Test_case--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        int max = 0;
        int fre, value;
        for (auto it : mp)
        {
            fre = it.second;
            if (fre > max)
            {
                max = fre;
                value = it.first;
            }
        }
        cout << value << " " << max << endl;
    }
}