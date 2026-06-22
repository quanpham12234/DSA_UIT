#include <iostream>
#include <cmath>
using namespace std;

struct toado
{
    int x;
    int y;
};

bool hople(toado A, toado B, toado C)
{
    double a = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
    double b = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
    double c = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));

    if (a + b <= c || a + c <= b || b + c <= a)
    return false;
    return true;
}

int main()
{
    int n;cin>>n;
    toado td[100];
    for (int i = 0; i < n ;i++)
    cin >> td[i].x >> td[i].y;

    for (int i = 0; i < n;i++)
    {
        for (int j = i+1; j < n;j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (hople(td[i],td[j],td[k]) == true)
                {
                    cout << "[(" << td[i].x << ", " << td[i].y << "), " << "(" << td[j].x << ", " << td[j].y << "), " << "(" << td[k].x << ", " << td[k].y << ")]" << endl;
                }
                else
                continue;
            }
        }
    }
    return 0;
}