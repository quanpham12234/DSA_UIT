#include <iostream>
#include <cmath>
using namespace std;

struct toaDo
{
    int x;
    int y;
};

double Do_dai(toaDo a, toaDo b)
{
    double answer = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    return answer;
}

double ChuVi(toaDo a, toaDo b, toaDo c)
{
    double answer = Do_dai(a, b) + Do_dai(a, c) + Do_dai(b, c);
    return answer;
}

bool ThangHang(toaDo a, toaDo b, toaDo c)
{
    int S = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return S == 0;
}

int main()
{
    int n;
    cin >> n;
    toaDo Diem[101];
    for (int i = 0; i < n; i++)
        cin >> Diem[i].x >> Diem[i].y;

    double ChuViMax = 0;
    int i1 = 0, j1 = 1, k1 = 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (ThangHang(Diem[i], Diem[j], Diem[k]) == true)
                    continue;

                double cv = ChuVi(Diem[i], Diem[j], Diem[k]);

                if (cv > ChuViMax ||
                    (fabs(cv - ChuViMax) < 1e-9 &&
                     (i < i1 || (i == i1 && j < j1) ||
                      (i == i1 && j == j1 && k < k1))))
                {
                    ChuViMax = cv;
                    i1 = i;
                    j1 = j;
                    k1 = k;
                }
            }
        }
    }
    cout << "[(" << Diem[i1].x << ", " << Diem[i1].y << "), " << "(" << Diem[j1].x << ", " << Diem[j1].y << "), " << "(" << Diem[k1].x << ", " << Diem[k1].y << ")]" << endl;
    return 0;
}