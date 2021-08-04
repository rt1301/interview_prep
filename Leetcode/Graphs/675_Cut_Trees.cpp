#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> off = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int sx, sy;
    int cutOffTree(vector<vector<int>> &forest)
    {
        int m = forest.size();
        int n = forest[0].size();
        if (forest[0][0] == 0)
            return -1;
        vector<int> heights;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (forest[i][j] != 0 && forest[i][j] != 1)
                {
                    heights.push_back(forest[i][j]);
                }
            }
        }
        sort(heights.begin(), heights.end());
        vector<vector<int>> temp;
        int total_steps = 0, target;
        for (int i = 0; i < heights.size(); i++)
        {
            target = heights[i];
            temp = forest;
            int h = find_height(sx, sy, target, temp);
            if (h == -1)
            {
                return -1;
            }
            total_steps += h;
            forest[sx][sy] = 1;
        }
        return total_steps;
    }
    int find_height(int xi, int yi, int target, vector<vector<int>> &temp)
    {
        if (temp[xi][yi] == target)
        {
            sx = xi;
            sy = yi;
            return 0;
        }
        int curr_steps = 1;
        queue<pair<int, int>> q;
        q.push({xi, yi});
        while (!q.empty())
        {
            int l = q.size();
            for (int z = 0; z < l; z++)
            {
                auto [i, j] = q.front();
                q.pop();
                for (int m = 0; m < 4; m++)
                {
                    int x = i - off[m][0];
                    int y = j - off[m][1];

                    if (x < 0 || y < 0 || x >= temp.size() || y >= temp.at(0).size() || temp[x][y] == 0 || temp[x][y] == -1)
                    {
                        continue;
                    }

                    if (temp[x][y] == target)
                    {
                        sx = x;
                        sy = y;
                        return curr_steps;
                    }

                    temp[x][y] = -1;

                    q.push({x, y});
                }
            }
            curr_steps++;
        }

        return -1;
    }
};