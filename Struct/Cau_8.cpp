#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

struct Diem
{
    float x, y;
};

struct TamGiac
{
    Diem A, B, C;

    float a, b, c;
    float P, S, R, r, ha, hb, hc;
    float gocA, gocB, gocC;

    void tinhChiSo()
    {
        a = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
        b = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
        c = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));

        P = (a + b + c) / 2;
        S = sqrt(P * (P - a) * (P - b) * (P - c));

        R = (a * b * c) / (4 * S);
        r = S / P;

        ha = 2 * S / a;
        hb = 2 * S / b;
        hc = 2 * S / c;

        gocA = acos((b * b + c * c - a * a) / (2 * b * c));
        gocB = acos((a * a + c * c - b * b) / (2 * a * c));
        gocC = acos((a * a + b * b - c * c) / (2 * a * b));
    }
};

int main()
{
    TamGiac tamgiac;
    cin >> tamgiac.A.x >> tamgiac.A.y >> tamgiac.B.x >> tamgiac.B.y >> tamgiac.C.x >> tamgiac.C.y;
    tamgiac.tinhChiSo();
    string choice;
    cin >> choice;
    if (tamgiac.S <= 0)
    {
        cout << "Day khong phai la tam giac";
        return 0;
    }
    else
    {
        if (choice == "P")
            cout << fixed << setprecision(2) << tamgiac.P;
        else if (choice == "S")
            cout << fixed << setprecision(2) << tamgiac.S;
        else if (choice == "gocA")
            cout << fixed << setprecision(2) << tamgiac.gocA;
        else if (choice == "gocB")
            cout << fixed << setprecision(2) << tamgiac.gocB;
        else if (choice == "gocC")
            cout << fixed << setprecision(2) << tamgiac.gocC;
        else if (choice == "a")
            cout << fixed << setprecision(2) << tamgiac.a;
        else if (choice == "b")
            cout << fixed << setprecision(2) << tamgiac.b;
        else if (choice == "c")
            cout << fixed << setprecision(2) << tamgiac.c;
        else if (choice == "R")
            cout << fixed << setprecision(2) << tamgiac.R;
        else if (choice == "r")
            cout << fixed << setprecision(2) << tamgiac.r;
        else if (choice == "ha")
            cout << fixed << setprecision(2) << tamgiac.ha;
        else if (choice == "hb")
            cout << fixed << setprecision(2) << tamgiac.hb;
        else if (choice == "hc")
            cout << fixed << setprecision(2) << tamgiac.hc;
    }
    return 0;
}