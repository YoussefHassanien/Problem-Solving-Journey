#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    int difference = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        difference = target - nums[i];
        if (map.find(difference) != map.end()) return { map[difference], i };
        map.insert({ nums[i], i });
    }

    return {};
    // vector<int> indices;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for(int j = 0; j < nums.size(); j++)
    //     {
    //         if(i == j) continue;
    //         if(nums[i] + nums [j] == target)
    //         {
    //             if(i < j)
    //             {
    //                 indices.emplace_back(i);
    //                 indices.emplace_back(j);
    //             }
    //             else 
    //             {
    //                 indices.emplace_back(j);
    //                 indices.emplace_back(i);
    //             }
    //             return indices;
    //         }
    //     }
    // }

}

void main()
{
    vector<int> v = { 1,2,4,8,5 };
    vector<int> result = twoSum(v, 7);
    cout << result[0] << " " << result[1];
}