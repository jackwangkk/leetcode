#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string largestNumber(vector<int> &nums);

int main()
{

    return 0;
}

string largestNumber(vector<int> &nums)
{
    string s = "";
    sort(nums.begin(), nums.end(), [](int a, int b)
         { return to_string(a) + to_string(b) > to_string(b) + to_string(a); });
    if (nums[0] == 0)
    {
        return "0";
    }

    for (int i = 0; i < nums.size(); i++)
    {

        s += to_string(nums[i]);
    }

    return s != "" ? s : "0";
}