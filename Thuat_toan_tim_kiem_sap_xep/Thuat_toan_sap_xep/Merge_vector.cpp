#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

void Merge(vector<int> &nums, int l,int m,int r)
{
    vector<int> temp;
    int i = l;
    int j = m + 1;

    while (i <= m && j <= r)
    {
        if (nums[i] <= nums[j])
        temp.push_back(nums[i++]);
        else
        temp.push_back(nums[j++]);
    }

    while (i <= m)
    temp.push_back(nums[i++]);

    while (j <= r)
    temp.push_back(nums[j++]);

    for (int k = 0; k < temp.size(); k++)
    nums[l + k] = temp[k];

    
}

void Merge_Sort(vector<int> &nums,int l,int r){
    if (l >= r) return;

    int m = (l + r)/2;

    Merge_Sort(nums,l, m);
    Merge_Sort(nums,m+1,r);
    
    Merge(nums,l,m,r);
}

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    srand(time(nullptr));
    for (int i = 0;i < n ;i++)
    nums[i] = rand() % 1000;

    Merge_Sort(nums,0, n-1);

    for (int i = 0;i < n ;i++)
    cout << nums[i] << " ";

    cout << endl;
    return 0;
}