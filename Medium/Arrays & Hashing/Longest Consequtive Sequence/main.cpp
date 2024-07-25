#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> sequence_set(nums.begin(), nums.end());
    int longest_sequence = 0;

    for (int i : sequence_set)
    {
        if (sequence_set.find(i - 1) == sequence_set.end())
        {
            int current_sequence = 0;
            while (sequence_set.find(i + current_sequence) != sequence_set.end())
                current_sequence += 1;
            longest_sequence = max(current_sequence, longest_sequence);
        }
    }

    return longest_sequence;
}

void main()
{
    vector<int> vec = { 2,20,4,10,3,4,5 };
    int result = longestConsecutive(vec);
    cout << result;
}

