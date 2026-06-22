#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

string Simplify(const string &path)
{
    stringstream ss(path);
    vector<string> st;
    string token;

    while (getline(ss,token,'/')){
        if (token == "" || token == ".")
            continue;

        else if (token == "..")
        {
            if (!st.empty())
                st.pop_back();
        }

        else
            st.push_back(token);
    }

    if (st.empty()) return "/";

    string res = "";
    for (const string& dir : st) {
        res += "/" + dir;
    }

    return res;
}
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string temp;
    while (cin >> temp && temp != "END")
    {
        cout << Simplify(temp) << "\n";
    }

    return 0;
}