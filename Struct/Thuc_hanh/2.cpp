/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

// ###INSERT CODE HERE -
struct DonThuc
{
    double HeSo;
    int mu;
};

int main()
{
    int n;
    cin >> n;
    DonThuc dt[101];
    for(int i = 0; i < n; i++)
        cin >> dt[i].HeSo >> dt[i].mu;

    bool first = true;

    for(int i = 0; i < n; i++)
    {
        double hs = dt[i].HeSo;
        int mu = dt[i].mu;

        if(hs == 0) continue;

        if(!first)
        {
            if(hs > 0) cout << "+";
            else cout << "-";
        }
        else
        {
            if(hs < 0) cout << "-";
        }

        double absHs = (hs > 0) ? hs : -hs;

        if(absHs != 1 || mu == 0)
            cout << absHs;

        if(mu != 0)
        {
            cout << "x";
            if(mu > 1)
                cout << "^" << mu;
        }

        first = false;
    }

    if(first) cout << "0";

    cout << endl;

    return 0;
}
