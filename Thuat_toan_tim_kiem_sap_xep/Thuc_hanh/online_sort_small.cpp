#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int> &a, int x)
{
    int l = 0;
    int r = a.size() - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;

        if (a[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a;
    int choice;

    while (true)
    {
        cin >> choice;
        if (choice == 0)
            break;

        int num;
        cin >> num;

        if (choice == 1)
        {
            auto it = lower_bound(a.begin(), a.end(), num);

            if (it == a.end() || *it != num)
            {
                a.insert(it, num);
            }
        }

        else
        {
            int found = binary_search(a, num);
            cout << found + 1 << "\n";
        }
    }

    return 0;
}