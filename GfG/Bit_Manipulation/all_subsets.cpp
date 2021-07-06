/****
 * Given a set of chars/integers
 * Print all their subsets
 ****/
#include <bits/stdc++.h>
using namespace std;
void printSubsets(vector<int> arr)
{
    int n = arr.size();
    int max = 1 << n; // 2^n
    for (int i = 0; i < max; i++)
    {

        for (int j = 0; j < n; j++)
        {
            // if jth bit is set in 'i' then print that
            // index element from the array
            if ((i & (1 << j)))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    vector<int> v = {1, 2, 3, 4};
    printSubsets(v);
    return 0;
}