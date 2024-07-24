#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    //unordered_map<int, int> count;
    //vector<vector<int>> freq(nums.size() + 1);

    //for (int n : nums) {
    //    count[n] = 1 + count[n];
    //}
    //for (const auto& entry : count) {
    //    freq[entry.second].push_back(entry.first);
    //}

    //vector<int> res;
    //for (int i = freq.size() - 1; i > 0; --i) {
    //    for (int n : freq[i]) {
    //        res.push_back(n);
    //        if (res.size() == k) {
    //            return res;
    //        }
    //    }
    //}

    //return res;

    unordered_map<int, int> freq_map;
    for (int i : nums)
        freq_map[i]++;

    vector<pair<int, int>> pairs_vec(freq_map.begin(), freq_map.end());
    sort(pairs_vec.begin(), pairs_vec.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second >= b.second;
        });

    vector<int> result;
    for (int i = 0; i < k; i++)
        result.emplace_back(pairs_vec[i].first);

    return result;
}

void main()
{
    vector<int> vec = { 1,2,2,3,3,3 };
    vector<int> result = topKFrequent(vec, 2);
    for (int i : result)
        cout << i << " ";
}