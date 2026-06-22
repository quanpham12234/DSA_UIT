#include <iostream>
using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    int a[100];
    bool co = false;
    for (int i = 0; i < n ; i++)
    {
        cin >> a[i];
        if (a[i] == x)
        co = true;
    }
    cout << co << endl;
    return 0;
}