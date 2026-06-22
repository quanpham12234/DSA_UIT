#include <iostream>
#include <algorithm>
using namespace std;

// Linear search . O(n)
// Binary search . O(logn) - DK: Mang da duoc sap xep

bool Linear_Search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return true;
    return false;
}

bool Binary_search_1(int a[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x)
            return true;
        else if (a[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

bool Binary_search_2(int a[], int l, int r, int x)
{
    if (l > r)
        return false;
    int mid = (l + r) / 2;
    if (a[mid] == x)
        return true;
    else if (a[mid] > x)
        return Binary_search_2(a, l, mid - 1, x);
    else
        return Binary_search_2(a, mid + 1, r, x);
}

// binary_search(a+x,a+y,key) => a[x] -> a[y-1]
// binary_search(a+1, a+4, key)

// Vector:
// binary_search(v.begin(), v.end(), key)
// binary_search(v.begin() + x, v.end() + y, key) => v[x] -> v[y-1]

int first_position(int a[],int n, int x)
{
    int res = -1;
    int l = 0;
    int r = n-1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (a[m] == x)
        {
            res = m;
            r = m-1;
        }
        else if (a[m] > x)
        r = m-1;
        else
        l = m +1;
    }
    return res;
}

int last_position(int a[],int n, int x)
{
    int l = 0;
    int r = n-1;
    int res = -1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (a[m] == x)
        {
            res = m;
            l = m+1;
        }
        else if ( a[m] > x)
        r = m-1;
        else
        l = m + 1;
    }
    return res;
}

int main()
{
    int n,x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n ;i++)
    cin >> a[i];
    if (binary_search(a,a+n,x)== true)
    cout << "Found";
    else
    cout << "Not Found";
    cout << endl;
    
    cout << first_position(a,n,x) << endl;
    cout << last_position(a,n,x) << endl;

    cout << "Tan suat: " << last_position(a,n,x) - first_position(a,n,x) + 1 << endl;
    return 0;
}