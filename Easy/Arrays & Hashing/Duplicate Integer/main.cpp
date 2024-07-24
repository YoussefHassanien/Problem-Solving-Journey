#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool hasDuplicate(vector<int>& nums)
{
    unordered_set<int> s;

    for (int i = 0; i < nums.size(); i++) 
    {
        if (s.find(nums[i]) != s.end()) return true;
        s.insert(nums[i]);
    }
    return false;
    //for (int i = 0; i < nums.size(); i++)
    //{
    //    for (int j = 0; j < nums.size(); j++)
    //    {
    //        if (i == j) continue;
    //        if (nums[i] == nums[j]) return true;
    //    }
    //}
    //return false;
}

void main()
{

}