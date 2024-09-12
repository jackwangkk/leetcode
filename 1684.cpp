#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int countConsistentStrings(string allowed, vector<string> &words);

int main()
{

    return 0;
}

int countConsistentStrings(string allowed, vector<string> &words)
{
    unordered_set<char> allowset(allowed.begin(), allowed.end());
    int ans = 0;
    for (const string &s : words)
    {
        bool consist = true;
        for (char c : s)
        {
            if (allowset.find(c) == allowset.end())
            {
                consist = false;
                break;
            }
        }
        if (consist)
            ans++;
    }
    return ans;
}