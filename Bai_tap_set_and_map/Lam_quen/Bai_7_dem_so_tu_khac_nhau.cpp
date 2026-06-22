#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int Test_case;
    cin >> Test_case;
    cin.ignore();
    while (Test_case--)
    {
        set<string> st;
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            st.insert(word);
        }
        cout << st.size() << endl;
    }
    return 0;
}