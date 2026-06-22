#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int Test_Case; cin >> Test_Case;
    cin.ignore();
    while(Test_Case--)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        set <string> st;
        bool found = false;
        while (ss >> word)
        {
            if (st.count(word) == 1)
            {
                cout << word << endl;
                break;
            }
            st.insert(word);
        }
    }
    return 0;
}