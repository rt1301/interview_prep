#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isRobotBounded(string inst)
    {
        int n = inst.length();
        int a = 0;
        int b = 0;
        int dir = 0; // N->0, E->1, S->2, W->4
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n; i++)
        {
            if (inst[i] == 'G')
            {
                a = a + dirs[dir][0];
                b = b + dirs[dir][1];
            }
            if (inst[i] == 'L')
            {
                dir = (dir + 3) % 4; //West Side rotation
            }
            if (inst[i] == 'R')
            {
                dir = (dir + 1) % 4;
            }
        }

        return (a == 0 && b == 0) || (dir != 0);
    }
};