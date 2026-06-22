#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int Test_Case; cin >> Test_Case;
    cin.ignore();
    while(Test_Case--)
    {
        string s;
        getline(cin,s);
        set<char> st;
        for (char x : s)
        {
            st.insert(tolower(x));
        }
        if (st.size() == 26)
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }
    return 0;
}