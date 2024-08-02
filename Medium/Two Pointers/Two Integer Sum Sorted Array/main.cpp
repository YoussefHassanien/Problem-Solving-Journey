#include<vector>
#include<iostream>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;

    while (i < j) {
        int curSum = numbers[i] + numbers[j];
        if (curSum > target)
            j--;
        else if (curSum < target)
            i++;
        else
            return { i + 1, j + 1 };
    }

    return {};
}

void main()
{
    std::vector<int> vec = { 1,2,3,4 };
    std::vector<int> result = twoSum(vec, 3);
    for (int i : result)
        std::cout << i << " ";
    std::cout << std::endl;
}