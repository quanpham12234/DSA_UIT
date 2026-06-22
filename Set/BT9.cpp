#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin.ignore();
        getline(cin, s);
        set<string> se;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            if (se.find(word) != se.end())
            {
                cout << word << endl;
                break;
            }
            se.insert(word);
        }
    }

    return 0;
}