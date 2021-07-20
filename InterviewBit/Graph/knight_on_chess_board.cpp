#include <bits/stdc++.h>
using namespace std;
class Cell
{
public:
    int x, y, dist;
    Cell(int x, int y, int dist)
    {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};
bool isInside(int x, int y, int a, int b)
{
    if (x >= 1 && x <= a && y >= 1 && y <= b)
        return true;
    return false;
}
int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    int x, y;
    bool visit[A + 1][B + 1];
    for (int i = 1; i <= A; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            visit[i][j] = false;
        }
    }
    visit[C][D] = true;
    vector<int> dx = {-2, -1, 1, 2, -2, -1, 1, 2};
    vector<int> dy = {-1, -2, -2, -1, 1, 2, 2, 1};
    queue<Cell> q;
    Cell st = Cell(C, D, 0);
    q.push(st);
    int ans = -1;
    while (!q.empty())
    {
        Cell t = q.front();
        q.pop();
        if (t.x == E && t.y == F)
        {
            ans = t.dist;
            break;
        }
        for (int i = 0; i < dx.size(); i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];
            if (isInside(x, y, A, B) && !visit[x][y])
            {
                visit[x][y] = true;
                Cell temp = Cell(x, y, t.dist + 1);
                q.push(temp);
            }
        }
    }
    return ans;
}
