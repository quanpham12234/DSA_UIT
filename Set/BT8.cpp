#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin.ignore();
        getline(cin, s);
        multiset<string> se;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            se.insert(word);
        }

        string max_val = *se.begin();
        string cur_val = *se.begin();
        int max_freq = 0;
        int cur_freq = 0;

        for (string x : se)
        {
            if (x == cur_val)
                cur_freq++;
            else
            {
                if (cur_freq > max_freq)
                {
                    max_val = cur_val;
                    max_freq = cur_freq;
                }
                cur_val = x;
                cur_freq = 1;
            }
        }

        if (cur_freq > max_freq)
        {
            max_val = cur_val;
            max_freq = cur_freq;
        }

        cout << max_val << endl;
    }

    return 0;
}