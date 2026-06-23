#include <iostream>
#include <stack>

using namespace std;

bool check_valid_parentheses(const string &s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '{' || c == '(' || c == '[')
            st.push(c);

        else
        {
            if (st.empty())
                return false;

            char temp = st.top();
            st.pop();
            if ((c == '}' && temp == '{') || (c == ']' && temp == '[') || (c == ')' && temp == '('))
                continue;

            else
                return false;
        }
    }

    return (st.empty() == true) ? true : false;
}

int main()
{
    string s;
    cin >> s;

    if (check_valid_parentheses(s) == true)
    {
        cout << "TRUE \n";
    }

    else
        cout << "FALSE \n";

    return 0;
}