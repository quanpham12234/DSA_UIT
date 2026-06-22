#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s;
        cin.ignore();
        getline(cin,s);
        stringstream ss(s);
        string word;
        set<string> se;
        while (ss >> word)
        {
            se.insert(word);
        }

        cout << se.size() << endl;
    }

    return 0;
}