#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int> &arr, int target)
{
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == target) return m;
        if (arr[m] < target) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

int lowerBound(const vector<int> &arr, int target) {
    int l = 0;
    int r = arr.size() - 1;

    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] >= target) r = m - 1;
        else l = m + 1;        
    }

    return l;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target; cin >> target;

    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    int lb_target; cin >> lb_target;
    
    int lb_result = lowerBound(arr,lb_target);
    if (lb_result != -1) {
        cout << "Lower bound index: " << lb_result << endl;
    } else {
        cout << "Lower bound not found in the array." << endl;
    }

    return 0;
}