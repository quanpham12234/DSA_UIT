#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin.ignore();
        getline(cin,s);

        multiset<char> se;
        for (char c : s)
            se.insert(c);

        char Max_Val = *se.begin();
        char Cur_Val = *se.begin();
        int Max_freq = 0;
        int Cur_freq = 0;

        for (char c : se)
        {
            if (c == Cur_Val)
                Cur_freq++;

            else
            {
                if (Cur_freq > Max_freq)
                {
                    Max_freq = Cur_freq;
                    Max_Val = Cur_Val;
                }

                Cur_freq = 1;
                Cur_Val = c;
            }
        }

        if (Cur_freq > Max_freq)
        {
            Max_freq = Cur_freq;
            Max_Val = Cur_Val;
        }

        cout << Max_Val << endl;
    }

    return 0;
}