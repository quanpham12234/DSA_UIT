#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complexity:
// Best: O(1)
// Worst: O(n^2)
// Average: O(n^2)

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0;i < n; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        swap(arr[i], arr[min]);
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0;i < n; i++)
        cin >> arr[i];

    selectionSort(arr);

    for (int i = 0;i < n; i++)
        cout << arr[i] << " ";

    return 0;
}