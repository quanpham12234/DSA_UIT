#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> Matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        string s, num;
        getline(cin, s);
        stringstream ss(s);

        while (ss >> num)
        {
            Matrix[i][stoi(num) - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << Matrix[i][j] << " ";

        cout << "\n";
    }

    return 0;
}