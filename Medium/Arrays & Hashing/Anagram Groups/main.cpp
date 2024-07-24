#include<vector>
#include<unordered_map>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;




vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> anagram_map;

    for (string str : strs)
    {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        anagram_map[sorted_str].emplace_back(str);
    }

    vector<vector<string>> anagram_groups_vec;
    for (auto pair : anagram_map)
    {
        anagram_groups_vec.emplace_back(pair.second);
    }

    return anagram_groups_vec;

    //unordered_map<string, vector<string>> freq_map;

    //for (string str : strs)
    //{
    //    vector<int> alphabet_count(26, 0);
    //    for (char c : str)
    //    {
    //        alphabet_count[c - 'a']++;
    //    }

    //    string keys;
    //    for (int i : alphabet_count)
    //    {
    //        keys += '#' + to_string(i);
    //    }

    //    freq_map[keys].emplace_back(str);
    //}

    //vector<vector<string>> anagram_groups_vec;
    //for (auto pair : freq_map)
    //{
    //    anagram_groups_vec.emplace_back(pair.second);
    //}

    //return anagram_groups_vec;
}

void main()
{
    vector<string> strings_vec{ "act","pots","tops","cat","stop","hat" };
    vector<vector<string>> strings_vec_vec = groupAnagrams(strings_vec);
    for (vector<string> vec : strings_vec_vec)
    {
        for (string str : vec)
        {
            cout << str << endl;
        }
    }
}