#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> diffWaysToCompute(string expression);

int main()
{
    string expression = "1+2+3*4";
    vector<int> result = diffWaysToCompute(expression);
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}

vector<int> diffWaysToCompute(string expression)
{
    vector<int> result;
    for (int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
        if (c == '+' or c == '-' or c == '*')
        {
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            for (int a : left)
            {
                for (int b : right)
                {
                    if (c == '+')
                    {
                        result.push_back(a + b);
                    }
                    else if (c == '-')
                    {
                        result.push_back(a - b);
                    }
                    else if (c == '*')
                    {
                        result.push_back(a * b);
                    }
                }
            }
        }
    }
    if (result.empty())
    {
        result.push_back(stoi(expression));
    }
    return result;
}