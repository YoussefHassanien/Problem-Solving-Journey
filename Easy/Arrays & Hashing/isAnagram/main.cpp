#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    //if (s.size() != t.size())
    //    return false;

    //sort(s.begin(), s.end());
    //sort(t.begin(), t.end());

    //return s == t;

     if(s.size() != t.size()) return false;

     unordered_map<char, int> s_map;
     unordered_map<char, int> t_map;

     for(auto i = 0; i < s.size(); i++)
     {
         s_map[s[i]]++;
         t_map[t[i]]++;
     }

     for(auto i = 0; i < s_map.size(); i++)
         if (s_map[i] != t_map[i]) return false;

     return true;
};

int main()
{
    string s = "racecar";
    string t = "carrace";

    bool c = isAnagram(s, t);
    cout << c;

    return 0;
}