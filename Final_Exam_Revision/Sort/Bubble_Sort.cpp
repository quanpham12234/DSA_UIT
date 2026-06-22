#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complexity:
// Best: O(1)
// Worst: O(n^2)
// Average: O(n^2)

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n; i++)
    {
        swapped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}