#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector <int> a(n);

    int Max = INT_MIN;
    int Min = INT_MAX;

    for (int i = 0;i < n;i++) {
        cin >> a[i];
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
    }

    int size = Max - Min + 1;
    vector<int> freq(size, 0);

    for (int i = 0;i < n ;i++)
        freq[a[i]]++;

    for (int i = Min; i <= Max; i++) {
        if (freq[i] == 0) continue;

        for (int j = 1; j <= freq[i];j++)
        {
            cout << i << " ";
        }
    }

    return 0;
}