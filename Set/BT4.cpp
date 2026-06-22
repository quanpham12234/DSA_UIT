#include <iostream>
#include <set>

using namespace std;

int main()
{
    int Test_Case;
    cin >> Test_Case;
    while (Test_Case--)
    {
        multiset<long long> se;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            se.insert(x);
        }

        long long current_val = *se.begin();
        long long max_val = *se.begin();
        int max_freq = 0;
        int cur_freq = 0;

        for (auto x : se)
        {
            if (x == current_val)
            {
                cur_freq++;
            }
            else
            {
                if (cur_freq > max_freq)
                {
                    max_freq = cur_freq;
                    max_val = current_val;
                }

                current_val = x;
                cur_freq = 1;
            }
        }

        if (cur_freq > max_freq)
        {
            max_freq = cur_freq;
            max_val = current_val;
        }

        cout << max_val << " " << max_freq << endl;
    }

    return 0;
}