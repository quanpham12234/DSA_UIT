#include <iostream>
#include <stack>

using namespace std;

bool valid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '{' || c == '(' || c == '[')
        {
            st.push(c);
        }

        else
        {
            if (st.empty())
                return false;

            if ((c == '}' && st.top() != '{') || (c == ')' && st.top() != '(') || (c == ']' && st.top() != '['))
                return false;

            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    while (true)
    {
        string s;
        cin >> s;
        if (s == "END")
            break;
        if (valid(s) == true)
        {
            cout << "TRUE\n";
        }
        else
            cout << "FALSE\n";
    }
    return 0;
}