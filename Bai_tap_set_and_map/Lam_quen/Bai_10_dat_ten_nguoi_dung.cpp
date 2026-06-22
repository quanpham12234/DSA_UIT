#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    cin.ignore();
    map<string,int> mp;
    while(n--)
    {
        string username;
        getline(cin,username);
        if (mp.count(username) == 0)
        cout << username<< endl;
        else
        cout << username << mp[username] << endl;
        mp[username]++;
    }
    return 0;


}