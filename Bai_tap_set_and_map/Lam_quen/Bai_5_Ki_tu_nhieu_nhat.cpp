#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int Test_case; cin >> Test_case;
    while( Test_case--)
    {
        cin.ignore();
        string s; getline(cin,s);
        map<char,int> mp;
        for (int i = 0; i < s.length() ;i++)
        mp[s[i]]++;
        int max = 0;
        char value;
        for (auto it : mp)
        {
            if (it.second > max)
            {
                max = it.second;
                value = it.first;
            }
        }
        cout << value << endl;
    }
    return 0;
}