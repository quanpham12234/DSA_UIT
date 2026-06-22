#include <iostream>
#include <string>
using namespace std;

struct CLB
{
    string Name;
    int win, draw, lose;
};

void input(CLB team[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin, team[i].Name);
        cin >> team[i].win >> team[i].draw >> team[i].lose;
    }
}

CLB top1(CLB team[], int n)
{
    int pointMax = 0;
    int Club = -1;
    for (int i = 0; i < n; i++)
    {
        int point = 0;
        point = team[i].win * 3 + team[i].draw;
        if (point > pointMax)
        {
            pointMax = point;
            Club = i;
        }
    }
    return team[Club];
}

int main()
{
    CLB Top1[20];
    int n;
    input(Top1,n);
    cout << top1(Top1,n).Name << endl;
    cout << top1(Top1,n).win << " " << top1(Top1,n).draw << " " << top1(Top1,n).lose << endl;
    return 0;
}