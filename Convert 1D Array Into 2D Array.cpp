#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n);

int main( )
{
    vector<int> original = {1,2,3,4};
    int m = 2, n = 2;
    vector<vector<int>> res = construct2DArray(original, m, n);
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (m * n != original.size()) {
        return {};
    }

    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < original.size(); i++) {
        res[i / n][i % n] = original[i];
    }

    return res;
}