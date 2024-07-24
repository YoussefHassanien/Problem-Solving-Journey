#include<vector>
#include<iostream>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;
    int prefix = 1;
    int postfix = 1;

    for (int i : nums)
    {
        result.emplace_back(prefix);
        prefix *= i;
    }

    auto it = nums.rbegin();
    auto it_2 = result.rbegin();
    for (; it != nums.rend() && it_2 != result.rend(); ++it, ++it_2)
    {
        *it_2 *= postfix;
        postfix *= *it;
    }

    return result;
}

void main()
{
    vector<int> vec = { 1,2,4,6 };
    vector<int> result = productExceptSelf(vec);
    for (int i : result)
        cout << i << " ";
}