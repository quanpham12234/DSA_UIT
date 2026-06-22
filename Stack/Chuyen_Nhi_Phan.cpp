#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int n;
        cin >> n;
        int temp = n;
        string ans = "";

        stack<int> st;

        while (temp != 0)
        {
            st.push(temp % 2);
            temp /= 2;
        }

        while (!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }

        cout << "Bien doi cua so " << n << " tu thap phan sang nhi phan: ";
        cout << ans << "\n";
    }

    return 0;
}