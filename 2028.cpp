#include <iostream>
#include <vector>
using namespace std;

vector<int> missingRolls(vector<int> &rolls, int mean, int n);

int main()
{
    vector<int> rolls = {3, 2, 4, 3};
    int mean = 4;
    int n = 2;
    vector<int> v = missingRolls(rolls, mean, n);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}

vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    int total = (rolls.size() + n) * mean;
    for (int i = 0; i < rolls.size(); i++)
    {
        total -= rolls[i];
    }
    vector<int> v;

    int m = total / n;
    if ((m == 6 and (total % n) != 0) or m <= 0 or m > 6)
    {
        return v;
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(m);
    }
    for (int i = 0; i < (total % n); i++)
    {
        v[i] += 1;
    }

    return v;
}