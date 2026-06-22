#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
int Linear_Search(int a[], int n, int x)
{
    int i = 0;
    while (i < n)
    {
        if (a[i] == x)
            return i;
        i++;
    }

    return -1;
}

int Linear_Search_Advanced(int a[], int n, int x)
{
    int i = 0;
    a[n] = x;
    while (a[i] != x)
        i++;
    if (i < n)
        return i;
    return -1;
}

int main()
{
    int n = 100000000;
    int *a = new int[n];

    for (int i = 0;i < n;i++)
    a[i] = i+1;

    int x; cin >> x;
    auto start = high_resolution_clock::now();

    cout << Linear_Search(a,n,x) << endl;

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time_Linear_Search: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();

    cout << Linear_Search_Advanced(a,n,x) << endl;

    end = high_resolution_clock::now();

    duration = duration_cast<microseconds>(end - start);

    cout << "Time_Linear_Search_Advanced: " << duration.count() << " microseconds" << endl;
}