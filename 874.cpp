#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles);

int main()
{
    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};
    cout << robotSim(commands, obstacles) << endl;

    return 0;
}

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    const long long m = 60001, lb = -30000;
    int max_dis=0;
    unordered_set<int> obset(obstacles.size());
    for (auto &ob : obstacles)
    {
        long long x = ob[0], y = ob[1];
        obset.insert(x*m+y);
    }
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int x=0,y=0,dx=0,dy=0,cur_dir=0;

    for (auto& c:commands)
    {
        switch (c)
        {
        case -1:
            cur_dir=(cur_dir+1)%4;
            break;

        case -2:
            cur_dir=(cur_dir+3)%4;
            break;

        default:
            dx=dir[cur_dir][0],dy=dir[cur_dir][1];
            for (int i = 0; i < c; i++)
            {
                x+=dx,y+=dy;
                if (obset.count(x*m+y)!=0)
                {
                    x-=dx,y-=dy;
                    break;
                }
                max_dis=max(max_dis,x*x+y*y);
            }
            break;
        }
    }
    

    return max_dis;
}