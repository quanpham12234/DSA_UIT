#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<string>res;

void init()
{
    queue<string> q;
    res.push_back("6");
    res.push_back("7");
    q.push("6");
    q.push("7");
    while (1)
    {
        string top = q.front();
        q.pop();
        if (top.length() == 15) break;
        res.push_back(top + "6");
        res.push_back(top + "7");
        q.push(top + "6");
        q.push(top + "7");
    }
}

int main()
{
    init();
    int n; cin >> n;
    vector<string> tmp;
    for (string x : res)
    {
        if (x.length() == n + 1)
        break;
        tmp.push_back(x);
    }
    reverse(tmp.begin(),tmp.end());
    for (string x : tmp)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}