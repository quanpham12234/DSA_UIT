#include <iostream>
#include <cstring>
using namespace std;

struct QuanLyXe
{
    char ID[20];
    int type;
};

int main()
{
    int n; cin >> n;
    QuanLyXe xe[100];
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cin.getline(xe[i].ID,20);
        cin >> xe[i].type;
    }
    int xe_may = 0, oto = 0, oto7 = 0, oto16 = 0;
    for (int i = 0;i < n;i++)
    {
        if (xe[i].type == 1)
        xe_may++;
        else if (xe[i].type == 2)
        oto++;
        else if (xe[i].type == 3)
        oto7++;
        else
        oto16++;
    }
    cout << "Xe may: " << xe_may << endl;
    cout << "Oto 4 cho: " << oto << endl;
    cout << "Oto 7 cho: " << oto7 << endl;
    cout << "Oto 16 cho: " << oto16 << endl;
    
    return 0;
}