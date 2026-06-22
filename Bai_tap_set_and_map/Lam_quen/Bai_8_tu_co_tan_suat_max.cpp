#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int Test_Case ; cin >> Test_Case;
    cin.ignore();
    while (Test_Case --)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        map<string, int> mp;
        string word;
        while(ss >> word)
        {
            mp[word]++;
        }
        int max = 0;
        string value;
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