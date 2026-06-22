#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int ngay;
    int thang;
    int nam;
};

struct HOPSUA
{
    string NhanHieu;
    double TrongLuong;
    Date HSD;
};

double nhapDSHopSua(HOPSUA a[], int &n)
{
    cin >> n;
    double tlmax = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].TrongLuong >> a[i].HSD.ngay >> a[i].HSD.thang >> a[i].HSD.nam;
        cin.ignore();
        getline(cin, a[i].NhanHieu);
        if (tlmax < a[i].TrongLuong)
            tlmax = a[i].TrongLuong;
    }
    return tlmax;
}

bool co (string s,string word)
{
    if (s.length()>= word.length() && s.substr(s.length() -word.length()) == word)
    return true;
    return false;
}

int main()
{
    HOPSUA a[100];
    int n;
    double tlmax = nhapDSHopSua(a, n);
    string word;
    cin >> word;
    for (int i = 0; i < n; i++)
    {
        if (a[i].TrongLuong != tlmax)
        continue;
        else
        {
            if (co(a[i].NhanHieu,word) == true)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}