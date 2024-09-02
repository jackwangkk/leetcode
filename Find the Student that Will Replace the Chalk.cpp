#include<iostream>
#include <numeric>
#include<vector>
using namespace std;

int chalkReplacer(vector<int>& chalk, int k);

int main()
{
    vector<int> chalk = {3,4,1,2};
    int k = 25;
    cout<<chalkReplacer(chalk,k)<<endl;

    return 0;
}

int chalkReplacer(vector<int>& chalk, int k)
{
    int chalk_sum = 0;
    for (int i = 0; i < chalk.size(); i++)
    {
        chalk_sum+=chalk[i];
        if (chalk_sum>k)
        {
            return i;
        }
        
    }
    k=k%chalk_sum;
    for (int i = 0; i < chalk.size(); i++)
    {
        k-=chalk[i];
        if (k<0)
        {
            return i;
        }
    }

    return -1;
}