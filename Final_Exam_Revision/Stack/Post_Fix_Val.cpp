#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int evaluatePostFix(string s)
{
    stringstream ss(s);
    stack<int> st;
    string token;

    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (token == "+")
                st.push(val1 + val2);
            else if (token == "-")
                st.push(val2 - val1);
            else if (token == "*")
                st.push(val1 * val2);
            else if (token == "/")
                st.push(val2 / val1);
        }
        else
            st.push(stoi(token));
    }

    return st.top();
}

int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string InfixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (char c : infix) {
        if (c == ' ') continue;;

        if (isalnum(c)) postfix += c;

        else if (c == '(') st.push('(');

        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty()) {
                st.pop();
            }
        }

        else {
            while (!st.empty() && getPrecedence(st.top()) >= getPrecedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {
        string temp;
        getline(cin, temp);

        int ans = evaluatePostFix(temp);
        cout << "Value: " << ans << "\n";
    }

    string infixExp = "a + b * (c ^ d - e) ^ (f + g * h) - i";
    
    cout << "Bieu thuc trung to (Infix):   " << infixExp << endl;
    cout << "Bieu thuc hau to (Postfix): " << InfixToPostfix(infixExp) << endl;

    // Test thử với một biểu thức số học đơn giản
    string mathExp = "1 + 2 * 3 - (4 / 2)";
    cout << "\nInfix 2:   " << mathExp << endl;
    cout << "Postfix 2: " << InfixToPostfix(mathExp) << endl;

    return 0;
}