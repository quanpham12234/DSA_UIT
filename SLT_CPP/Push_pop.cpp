#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> ans;
    while (n--)
    {
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            int val; cin >> val;
            ans.push_back(val);
        }
        else
        {
            if (!ans.empty())
            {
                ans.pop_back();
            }
        }
    }

    if (ans.empty())
    {
        cout << "EMPTY" << endl;
        return 0;
    }

    for (auto it : ans)
    cout << it << " ";

    return 0;
}