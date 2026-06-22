#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;

int h_max = 0;

void print_array(vector<int> array, int left, int right)
{
    int n = array.size();
    for (int i = h_max; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[j] < i)
            {
                cout << " ";
            }
            else
            {
                if (j >= left && j < right)
                    cout << "-";
                else
                    cout << "#";
            }
            if (j < n - 1)
                cout << " ";
        }
        cout << "\n";
    }
}

void Merge(vector<int> &array, int left, int mid, int right)
{
    vector<int> l(array.begin() + left, array.begin() + mid);
    vector<int> r(array.begin() + mid, array.begin() + right);

    int k = left;
    int i = 0, j = 0;

    while (i < l.size() && j < r.size())
    {
        if (l[i] <= r[j])
            array[k++] = l[i++];
        else
            array[k++] = r[j++];
    }

    while (i < l.size())
    {
        array[k++] = l[i++];
    }

    while (j < r.size())
    {
        array[k++] = r[j++];
    }
}

void Merge_Sort(vector<int> &array, int left, int right)
{
    if (left >= right - 1) return;
    
    int mid = (left + right) / 2;
    Merge_Sort(array, left, mid);
    Merge_Sort(array, mid, right);
    
    Merge(array, left, mid, right);
    print_array(array, left, right);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> a;
    int x;

    while (ss >> x)
    {
        a.push_back(x);
    }

    if(a.empty()) return 0;

    h_max = *max_element(a.begin(), a.end());

    print_array(a, -1, -1);

    Merge_Sort(a, 0, a.size());

    print_array(a, -1, -1);
    return 0;
}