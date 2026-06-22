/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
// ###INSERT CODE HERE -
#include <iostream>
#include <vector>
using namespace std;

struct Toa_do
{
    double x, y, z;
};

int index_check(Toa_do *a, int n, Toa_do check)
{
    for (int i = 0;i < n;i++)
    {
        if (a[i].x == check.x && a[i].y == check.y && a[i].z == check.z)
        return i;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    Toa_do *a = new Toa_do[n];

    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;

    int m; cin >> m;
    while (m--)
    {
        Toa_do check;
        cin >> check.x >> check.y >> check.z;

        int ans = index_check(a,n,check);

        if (ans == -1) cout << "KHONG" << endl;
        else cout << ans << endl;
    }

    return 0;

}