#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubarray(vector<int> &nums);

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << longestSubarray(nums) << endl;

    return 0;
}

int longestSubarray(vector<int> &nums)
{
    int max = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    int longest = 0;
    int cu = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == max)
        {
            cu++;
        }
        else
        {
            if (cu > longest)
            {
                longest = cu;
            }
            cu = 0;
        }
    }
    if (cu > longest)
    {
        longest = cu;
    }
    return longest;
}