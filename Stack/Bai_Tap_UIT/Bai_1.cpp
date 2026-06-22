#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> st;
    string s;
    cin >> s;

    for (char c : s)
    {
        if (c == '*')
        {
            if (st.empty())
                cout << "EMPTY";
            else
                cout << st.top();
            cout << "\n";

            st.pop();
        }

        else {
            st.push(c);
        }
    }

    return 0;
}