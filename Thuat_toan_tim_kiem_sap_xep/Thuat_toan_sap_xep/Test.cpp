#include <iostream>
using namespace std;

struct DIEM{
    int x, y;
};

struct DAGIAC{
    int n;
    DIEM *p;
};

void NhapMotDiem(DIEM &a)
{
    cin >> a.x;
    cin >> a.y;
}

DAGIAC NhapMotDaGiac(){
    DAGIAC A;
    cin >> A.n;

    for (int i = 0;i < A.n ;i++)
    {
        DIEM a;
        NhapMotDiem(a);
        A.p[i] = a;
    }
    return A;
}

int main(){
    DAGIAC B;
    B = NhapMotDaGiac();
    return 0;
}
