#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2);

int main()
{
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    vector<string> ans = uncommonFromSentences(s1, s2);
    for (string s : ans)
    {
        cout << s << " ";
    }

    return 0;
}

vector<string> uncommonFromSentences(string s1, string s2)
{
    unordered_map<string, int> m;
    string temp = "";
    for (char c : s1)
    {
        if (c != ' ')
        {
            temp += c;
        }
        else
        {
            m[temp]++;
            temp = "";
        }
    }
    m[temp]++;
    temp = "";
    for (char c : s2)
    {
        if (c != ' ')
        {
            temp += c;
        }
        else
        {
            m[temp]++;
            temp = "";
        }
    }
    m[temp]++;
    temp = "";
    vector<string> ans;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second==1)
        {
            ans.push_back(it->first);
        }
    }
    return ans;
}