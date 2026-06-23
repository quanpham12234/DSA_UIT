#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");

    while (n--)
    {
        cout << q.front() << "\n";
        q.push(q.front() + "0");
        q.push(q.front() + "1");

        q.pop();
    }

    return 0;
}