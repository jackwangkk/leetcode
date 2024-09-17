#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinDifference(vector<string> &timePoints);

int main()
{
    vector<string> timePoints = {"23:59", "00:00"};
    cout << findMinDifference(timePoints) << endl;

    return 0;
}

int findMinDifference(vector<string> &timePoints)
{
    vector<int> v(timePoints.size());
    for (int i = 0; i < timePoints.size(); i++)
    {
        int h = stoi(timePoints[i].substr(0, 2));
        int m = stoi(timePoints[i].substr(3));
        v[i] = h * 60 + m;
    }
    sort(v.begin(), v.end());
    int ans = INT32_MAX;
    for (int i = 1; i < v.size(); i++)
    {
        int diff = v[i] - v[i - 1];
        ans = min(ans, diff);
    }
    ans = min(ans, v[0] + 1440 - v[v.size() - 1]);
    return ans;
}