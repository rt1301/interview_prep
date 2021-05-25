#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == 0 && nums[i-1]==0){ //case when k=0
                return true;
            }
        }
        if(k!=0){
            k = abs(k); //making sure k is always positive
            unordered_set<int>s; //to store the remainders
            int twoAhead[2] = {nums[0]%k,0}; //odd/even buffer to check the two num sequence
            
            for(int i=1;i<nums.size();i++){
                twoAhead[i%2] = (nums[i] + twoAhead[(i+1)%2])%k; //adding remainder of two adj sums
                if(twoAhead[i%2] == 0 || s.find(twoAhead[i%2]) != s.end()){
                    return true;
                }
                s.insert(twoAhead[(i+1)%2]);
            }
        }
        
        return false;
        
    }
};