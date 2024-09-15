#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findTheLongestSubstring(string s);

int main()
{
    string s;
    cin >> s;
    cout << findTheLongestSubstring(s) << endl;

    return 0;
}

int findTheLongestSubstring(string s)
{
    vector<int> pos(1 << 5, -1);
    int status = 0;
    int n = s.size();
    pos[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == 'a')
        {
            status ^= 1 << 0;
        }
        else if (ch == 'e')
        {
            status ^= 1 << 1;
        }
        else if (ch == 'i')
        {
            status ^= 1 << 2;
        }
        else if (ch == 'o')
        {
            status ^= 1 << 3;
        }
        else if (ch == 'u')
        {
            status ^= 1 << 4;
        }
        if (~pos[status])
        {
            int cu = (!status) ? i - pos[status] + 1 : i - pos[status];
            if (cu > ans)
            {
                ans = cu;
            }
        }
        else
        {
            pos[status] = i;
        }
    }
    return ans;
}