/****
 * Given a matrix of size n x m, where every row and column is sorted 
 * in increasing order, and a number x. Find whether element x is present 
 * in the matrix or not.
 ****/
class Solution
{
public:
    //Function to search a given number in row-column sorted matrix.
    bool binarySearch(vector<int> v, int key)
    {
        int i = 0;
        int j = v.size() - 1;
        int m = 0;
        while (i <= j)
        {
            m = i + (j - i) / 2;
            if (v[m] == key)
            {
                return true;
            }
            else if (v[m] < key)
            {
                i = m + 1;
            }
            else
            {
                j = m - 1;
            }
        }
        return false;
    }
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] <= x && matrix[i][m - 1] >= x)
            {
                if (binarySearch(matrix[i], x))
                {
                    return true;
                }
            }
        }
        return false;
    }
};