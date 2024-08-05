#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int maxArea(vector<int>& heights)
{
    int area = 0;
    size_t j = heights.size() - 1, i = 0;
    while (j > i)
    {
        if ((min(heights[i], heights[j]) * (j - i)) >= area)
            area = (min(heights[i], heights[j])) * (j - i);
        if (heights[i] <= heights[j])
            i++;
        else
            j--;
    }

    return area;
}

void main()
{
    vector<int> vec = { 1,8,6,2,5,4,8,3,7 };
    cout << "Maximum area = " << maxArea(vec) << endl;
}