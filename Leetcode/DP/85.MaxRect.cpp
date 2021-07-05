#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void buildHist(vector<vector<char>> m, vector<vector<int>> &graph)
    {
        int r = m.size();
        int c = m[0].size();

        for (int i = 0; i < c; i++)
        {
            graph[0][i] = m[0][i] - '0';
        }

        for (int i = 1; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (m[i][j] == '1')
                {
                    graph[i][j] = 1 + graph[i - 1][j];
                }
                else
                {
                    graph[i][j] = 0;
                }
            }
        }
    }
    int maxHeight(vector<int> hist)
    {
        int max_area = 0;
        int tp;
        int area = 0;
        int i = 0;
        int n = hist.size();
        stack<int> s;
        while (i < n)
        {
            if (s.empty() || hist[s.top()] <= hist[i])
            {
                s.push(i++);
            }
            else
            {
                tp = s.top();
                s.pop();
                area = s.empty() ? hist[tp] * i : hist[tp] * (i - s.top() - 1);
                max_area = max(max_area, area);
            }
        }

        while (!s.empty())
        {
            tp = s.top();
            s.pop();
            area = s.empty() ? hist[tp] * i : hist[tp] * (i - s.top() - 1);
            max_area = max(max_area, area);
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> graph(r, vector<int>(c));
        buildHist(matrix, graph);
        int result = maxHeight(graph[0]);
        for (int x = 1; x < r; x++)
        {
            result = max(result, maxHeight(graph[x]));
        }
        return result;
    }
};