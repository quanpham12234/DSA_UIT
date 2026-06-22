#include <iostream>
#include <queue>
#include <string>

using namespace std;

vector<long long> res;
long long ans[101];

void init()
{
    queue<string> q;
    q.push("9");
    res.push_back(9);
    while (1)
    {
        string top = q.front();
        q.pop();
        if (top.length() == 11)
            break;
        res.push_back(stoll(top + "0"));
        res.push_back(stoll(top + "9"));

        q.push(top + "0");
        q.push(top + "9");
    }
    int count = 0;
    for (int i = 1; i <= 100; i++)
        for (long long x : res)
            if (x % i == 0)
            {
                ans[i] = x;
                count++;
                break;
            }

    cout << count << endl;
}

int main()
{
    init();
    int n; cin >> n;
    cout << ans[n] << endl;
    return 0;
}