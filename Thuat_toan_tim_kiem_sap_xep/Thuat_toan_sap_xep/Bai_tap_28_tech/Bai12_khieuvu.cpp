#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m,n; cin >> m >> n;
    int b[100];
    int c[100];
    for (int i = 0; i < m;i++)
    cin >> b[i];
    for (int i = 0; i < n;i++)
    cin >> c[i];
    int count = 0;
    int i = 0;
    int j = 0;
    sort(b, b + m);
    sort(c,c+n);
    while ( i < m && j < n)
    {
        if (b[i] > c[j])
        {
            count++;
            i++;
            j++;
        }
        else
            i++;
    }
    cout << count << endl;
    return 0;
    
}