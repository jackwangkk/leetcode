#include <iostream>
#include <vector>
using namespace std;

int minBitFlips(int start, int goal);

int main()
{
    int a, b;
    cin >> a >> b;
    cout << minBitFlips(a, b) << endl;

    return 0;
}

int minBitFlips(int start, int goal)
{
    vector<int> bit;
    while (start != 0)
    {
        bit.push_back(start % 2);
        start = start / 2;
    }
    vector<int> goal_bit;
    while (goal != 0)
    {
        goal_bit.push_back(goal % 2);
        goal = goal / 2;
    }
    int ans = 0;
    if (bit.size() > goal_bit.size())
    {
        for (int i = 0; i < goal_bit.size(); i++)
        {
            if (bit[i] != goal_bit[i])
            {
                ans++;
            }
        }
        for (int i = goal_bit.size(); i < bit.size(); i++)
        {
            if (bit[i] == 1)
            {
                ans++;
            }
        }
    }
    else
    {
        for (int i = 0; i < bit.size(); i++)
        {
            if (bit[i] != goal_bit[i])
            {
                ans++;
            }
        }
        for (int i = bit.size(); i < goal_bit.size(); i++)
        {
            if (goal_bit[i] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}