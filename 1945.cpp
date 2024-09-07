#include <iostream>
#include <string>
using namespace std;

int getLucky(string s, int k);

int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << getLucky(s, k) << endl;

    return 0;
}

int getLucky(string s, int k)
{
    string str = "";
    for (char c : s)
    {
        str += to_string(c - 'a' + 1);
    }
    for (int i = 0; i < k; i++)
    {
        int sum = 0;
        for (char c : str)
        {
            sum += c - '0';
        }
        str = to_string(sum);
    }
    return stoi(str);
}