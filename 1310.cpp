#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries);

int main()
{
    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    vector<int> res = xorQueries(arr, queries);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}

 vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
 {
        vector<int> res;
        vector<int> xorArr;
        xorArr.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            xorArr.push_back(xorArr[i - 1] ^ arr[i]);
        }
        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] == 0)
            {
                res.push_back(xorArr[queries[i][1]]);
            }
            else
            {
                res.push_back(xorArr[queries[i][0] - 1] ^ xorArr[queries[i][1]]);
            }
        }
        return res;
 }