#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> s;
    int choice;

    while (true)
    {
        cin >> choice;

        if (choice == 0)
            break;

        int num;
        if (choice == 1)
        {
            cin >> num;
            s.insert(num);
        }

        else if (choice == 2)
        {
            cin >> num;
            auto it = s.find(num);
            if (it != s.end())
            {
                cout << 1;
            }
            else
                cout << 0;

            cout << "\n";
        }

        else if (choice == 3)
        {
            cin >> num;
            s.erase(num);
        }
    }

    return 0;
}