#include<vector>
#include<string>
#include<iostream>
using namespace std;


string encode(vector<string>& strs) {
    string encoded_str = "";
    for (string str : strs)
        encoded_str += to_string(str.size()) + "#" + str;

    return encoded_str;
}

vector<string> decode(string s) {
    size_t i = 0;
    vector<string> result;
    string temp_str = "";

    while (i < s.size())
    {
        int j = i;
        while (s[j] != '#')
            j++;

        int length = stoi(s.substr(i, j));
        temp_str = s.substr(j + 1, length);
        result.emplace_back(temp_str);
        i = j + 1 + length;
    }

    return result;
}


void main()
{
    vector<string> str_vec = {"neet","code","love","you"};
    string str = encode(str_vec);
    str_vec = decode(str);
    for (string i : str_vec)
        cout << i << endl;
}