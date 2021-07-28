/****
 * Given a binary matrix. Find the maximum area of a rectangle 
 * formed only of 1s in the given matrix.
 ****/
#include <bits/stdc++.h>
using namespace std;
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    vector<int> nsl(int arr[], int n)
    {
        vector<int> v;
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                v.push_back(-1);
            }
            else if (!s.empty() && s.top().first < arr[i])
            {
                v.push_back(s.top().second);
            }
            else if (!s.empty() && s.top().first >= arr[i])
            {
                while (!s.empty() && s.top().first >= arr[i])
                {
                    s.pop();
                }
                if (s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        return v;
    }
    vector<int> nsr(int arr[], int n)
    {
        vector<int> v;
        stack<pair<int, int>> s;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                v.push_back(n);
            }
            else if (!s.empty() && s.top().first < arr[i])
            {
                v.push_back(s.top().second);
            }
            else if (!s.empty() && s.top().first >= arr[i])
            {
                while (!s.empty() && s.top().first >= arr[i])
                {
                    s.pop();
                }
                if (s.empty())
                    v.push_back(n);
                else
                    v.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        reverse(v.begin(), v.end());
        return v;
    }
    int mah(int arr[], int n)
    {
        vector<int> id1 = nsl(arr, n);
        vector<int> id2 = nsr(arr, n);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int temp = arr[i] * ((id2[i] - id1[i]) - 1);
            ans = max(ans, temp);
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // Your code here
        int arr[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = M[0][i];
        }
        int mx = mah(arr, m);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 0)
                {
                    arr[j] = 0;
                }
                else
                {
                    arr[j] += M[i][j];
                }
            }
            mx = max(mx, mah(arr, m));
        }
        return mx;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends