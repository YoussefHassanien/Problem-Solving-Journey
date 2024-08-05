#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int trap(vector<int>& height) {
    if (height.empty())
        return 0;
    size_t i = 0, j = height.size() - 1;
    int leftMax = height[i], rightMax = height[j], area = 0;
    while (j > i)
    {
        if (leftMax > rightMax)
        {
            j--;
            rightMax = max(rightMax, height[j]);
            area += rightMax - height[j];
        }
        else
        {
            i++;
            leftMax = max(leftMax, height[i]);
            area += leftMax - height[i];
        }
    }

    return area;
}

void main()
{
    vector<int> vec = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << "Maximum area of the trapped rain water = " << trap(vec) << endl;
}