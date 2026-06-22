#include <iostream>
#include <vector>

using namespace std;

// Complexity:
// Best: O(1)
// Worst: O(n^2)
// Average: O(n^2)

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = i - 1;

        while (pos >= 0 && arr[pos] > key) {
            arr[pos + 1] = arr[pos];
            pos--;
        }

        arr[pos + 1] = key;
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";

    return 0;
}