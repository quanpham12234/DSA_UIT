#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int bcnn(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;

    int r = 1;
    while (2 * r % a != 0 || 3 * r % b != 0)
    {
        r++;
    }

    int l = bcnn(a, b);

    cout << 4 * r + 6 * l << endl;

    return 0;
}