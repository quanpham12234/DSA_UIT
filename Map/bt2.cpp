#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> s;
    int choice;

    while (true) {
        cin >> choice;

        if (choice == 0) break;

        int num;
        cin >> num;
        if (choice == 1) {
            s.insert(num);
        }

        else if (choice == 2) {
            auto it = s.find(num);
            if (it != s.end())
                cout << 1;

            else cout << 0;

            cout << "\n";
        }
    }

    return 0;
}