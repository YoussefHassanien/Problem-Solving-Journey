#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
     //unordered_map<int, vector<int>> freq_map;
     //for(int i = 0; i < nums.size(); i++)
     //{
     //    freq_map[nums[i]].emplace_back(i);
     //}

     //for(pair<int, vector<int>> freq_pairs: freq_map)
     //{
     //    if(freq_pairs.second.size() >= 2)
     //    {
     //        for(int i = 0; i < freq_pairs.second.size() - 1; i++)
     //        {
     //            if(abs(freq_pairs.second[i] - freq_pairs.second[i + 1]) <= k) return true;
     //        }
     //    }
     //}

     //return false;

    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.count(nums[i]))
        {
            if (abs(i - mp[nums[i]]) <= k) return true;
        }
        mp[nums[i]] = i;
    }

    return false;
}

void main()
{
    vector<int> v{ 1,2,3,1,2,3 };
    int k = 2;
    bool c = containsNearbyDuplicate(v, k);

    if (c) cout << "True" << endl;
    else cout << "False" << endl;

}