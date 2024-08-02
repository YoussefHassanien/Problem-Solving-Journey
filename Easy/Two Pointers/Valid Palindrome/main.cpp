#include<cctype>
#include<iostream>
using namespace std;

bool isPalindrome(string s) {
    string alphanumeric_str = "";
    for (char c : s)
    {
        if (isalnum(c))
            alphanumeric_str += tolower(c);
    }

    int i = 0;
    int j = alphanumeric_str.size() - 1;

    while (i < j)
    {
        if (alphanumeric_str[i] != alphanumeric_str[j])
            return false;
        i++;
        j--;
    }

    return true;
}

void main()
{
    string s = "Was it a car or a cat I saw?";
    if (isPalindrome(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}