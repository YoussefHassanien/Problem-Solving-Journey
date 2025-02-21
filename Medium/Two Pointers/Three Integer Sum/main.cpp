#include<vector>
#include<algorithm>
#include<iostream>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

    sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        size_t l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum > 0)
                r--;
            else if (sum < 0)
                l++;
            else
            {
                res.push_back({ nums[i], nums[l], nums[r] });
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1])
                    l++;
            }
        }
    }
    return res;
}

void main()
{
    std::vector<int> vec = { -1,0,1,2,-1,-4 };
    std::vector<std::vector<int>> res = threeSum(vec);
    for (std::vector<int> v : res)
    {
        for (int i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}