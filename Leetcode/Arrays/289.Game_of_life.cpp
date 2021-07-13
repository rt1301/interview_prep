#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> res;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                temp[j] = board[i][j];
            }
            res.push_back(temp);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int lc = 0, dc = 0;
                vector<pair<int, int>> nc = {{i - 1, j}, {i + 1, j}, {i, j + 1}, {i, j - 1}, {i + 1, j + 1}, {i - 1, j - 1}, {i + 1, j - 1}, {i - 1, j + 1}};
                for (int k = 0; k < nc.size(); k++)
                {
                    if ((nc[k].first >= 0 && nc[k].first < m) && (nc[k].second >= 0 && nc[k].second < n))
                    {
                        if (res[nc[k].first][nc[k].second])
                        {
                            lc++;
                        }
                        else
                        {
                            dc++;
                        }
                    }
                }
                if (board[i][j] && lc < 2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] && (lc == 2 || lc == 3))
                {
                    board[i][j] = 1;
                }
                else if (board[i][j] && lc > 3)
                {
                    board[i][j] = 0;
                }
                else if (!board[i][j] && lc == 3)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = res[i][j];
                }
            }
        }
    }
};