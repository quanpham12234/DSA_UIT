#include <iostream>
#include <algorithm>

using namespace std;

// Lower_bound (iter1, iter2, key) [iter1;iter2) => tra ve vi tri cua phan tu dau tien >= key
// Ap dung cho mang duoc sap xep, set, map
// Neu ma tat ca phan tu trong mang deu nho hon key => tra ve iter2
// 7 2
// 1 2 2 3 4 5 6

int main()
{
    int n,x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n ;i++)
    cin >> a[i];
    auto it = lower_bound(a,a+n,x); // tim vi tri dau tien cua phan tu >= x nam trong a
    if (it != (a+n))
    cout << *it << " " << it - a << endl;
    else
    cout << "Khong co" << endl;
    return 0;
}