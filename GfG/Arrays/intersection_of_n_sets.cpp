#include<bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int>v, int x){
    int n = v.size();
    int l = 0;
    int r = n-1;
    int m = 0;
    while (l<r)
    {
        m = l + (r-l)/2;
        if(v[m] == x){
            return true;
        }
        if(v[m]<x){
            l = m+1;
        }else{
            r = m-1;
        }
    }
    return false;
}
vector<int>intersection(vector<vector<int>>sets){
    int n = sets.size();
    int smallIndex = 0;
    int minSize = sets[0].size();
    for(int i=1;i<n;i++){
        sort(sets[i].begin(),sets[i].end());
        if(minSize>sets[i].size()){
            smallIndex = i;
            minSize = sets[i].size();
        }
    }
    map<int,int>mp;
    vector<int>ans;
    for(int i=0;i<sets[smallIndex].size();i++){
        if (mp[sets[smallIndex][i]])
            mp[sets[smallIndex][i]]++;
        else{
            mp[sets[smallIndex][i]] = 1;
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        int ele = it->first;
        int freq = it->second;
        int bFound = true;

        for(int j=0;j<sets.size();j++){
            if(j!=smallIndex){
                if (binarySearch(sets[j],ele))
                {
                    int lIndex = lower_bound(sets[j].begin(), sets[j].end(), ele) - sets[j].begin();
                    int rIndex = upper_bound(sets[j].begin(), sets[j].end(), ele) - sets[j].begin();
                    freq = min(freq, rIndex - lIndex);
                }
                else
                {
                    bFound = false;
                    break;
                }
            }
        }

        if(bFound){
            for(int k=0;k<freq;k++){
                ans.push_back(ele);
            }
        }
    }

    return ans;
}

void printset(vector<int> set)
{
    for (int i = 0; i < set.size(); i++)
        cout << set[i] << " ";
}

// Test case
void TestCase1()
{
    vector<vector<int>> sets;
    vector<int> set1;
    set1.push_back(1);
    set1.push_back(1);
    set1.push_back(2);
    set1.push_back(2);
    set1.push_back(5);

    sets.push_back(set1);

    vector<int> set2;
    set2.push_back(1);
    set2.push_back(1);
    set2.push_back(4);
    set2.push_back(3);
    set2.push_back(5);
    set2.push_back(9);

    sets.push_back(set2);

    vector<int> set3;
    set3.push_back(1);
    set3.push_back(1);
    set3.push_back(2);
    set3.push_back(3);
    set3.push_back(5);
    set3.push_back(6);

    sets.push_back(set3);

    vector<int> r = intersection(sets);

    printset(r);
}

// Driver program to test above functions
int main()
{
    TestCase1();
    return 0;
}