#include<bits/stdc++.h>
using namespace std;
class coord
{
public:
    int x;
    int y;
    int wt;
    coord(int a, int b, int w)
    {
        x = a;
        y = b;
        wt = w;
    }
};
bool operator<(coord a, coord b)
{
    if (a.wt == b.wt)
    {
        if (a.x != b.x)
            return (a.x < b.x);
        else
            return (a.y < b.y);
    }
    return (a.wt < b.wt);
}
bool isValid(int x, int y, int n)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        return true;
    }
    return false;
}

int minimumCostPath(vector<vector<int>> &grid)
{
    // Code here
    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0, 1, 0, -1};
    int n = grid.size();
    int dis[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = INT_MAX;
        }
    }
    set<coord> st;
    coord src = coord(0, 0, 0);
    st.insert(src);
    dis[0][0] = grid[0][0];
    while (!st.empty())
    {
        coord k = *st.begin();
        st.erase(st.begin());

        for (int i = 0; i < 4; i++)
        {
            int x = k.x + row[i];
            int y = k.y + col[i];
            if (!isValid(x, y, n))
            {
                continue;
            }
            if (dis[x][y] > (dis[k.x][k.y] + grid[x][y]))
            {
                if (dis[x][y] != INT_MAX)
                {
                    st.erase(coord(x, y, dis[x][y]));
                }
                dis[x][y] = dis[k.x][k.y] + grid[x][y];

                st.insert(coord(x, y, dis[x][y]));
            }
        }
    }
    return dis[n - 1][n - 1];
}

int main(){

    vector<vector<int>> grid = { {9, 4, 9, 9},
                                 {6, 7, 6, 4},
                                 {8, 3, 3, 7},
                                 {7, 4, 9, 10}
    };
    cout<<minimumCostPath(grid)<<endl;
    return 0;
}