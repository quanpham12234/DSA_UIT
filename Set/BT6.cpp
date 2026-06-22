#include <iostream>
#include <string>
#include <set>

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
        set<char> se;

        for (char c : s)
            se.insert(tolower(c));

        if (se.size() == 26)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}