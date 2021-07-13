/****
 * Given a boolean expression with following symbols. 
 *  'T' ---> true 
 *  'F' ---> false
 * And following operators filled between symbols 
 * & - AND
 * | - OR
 * ^ - XOR
 * Count the number of ways we can parenthesize the expression so that 
 * the value of expression evaluates to true. 
 ****/
#include<bits/stdc++.h>
using namespace std;
// Using a hashmap for dp table to avoid 3D matrix formation
unordered_map<string, int>mp;
// Memoized solution
int solveMemo(string s, int i, int j, bool flag){
    // Base Conditions
    if(i>j) return 0;
    if(i == j){
        if(flag){
            return s[i] == 'T';
        }else{
            return s[i] == 'F';
        }
    }
    // Checking if given expression already exists in hashmap
    // temp = i + ' ' + j + ' ' + flag
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(flag));

    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }
    else{
        // Original Recursion code
        int ans = 0;
        for(int k=i+1;k<j;k++){
            int lt = solveMemo(s,i,k-1,true);
            int lf = solveMemo(s,i,k-1,false);
            int rt = solveMemo(s,k+1,j,true);
            int rf = solveMemo(s,k+1,j,false);

            if(s[k] == '&'){
                if(flag){
                    ans+=(rt*lt);
                }else{
                    ans+=(rf*lf + rf*lt + rt*lf);
                }
            }else if(s[k] == '|'){
                if(flag){
                    ans+=(rt*lt + rf*lt + lf*rt);
                }else{
                    ans+=(rf*lf);
                }
            }else{
                if(flag){
                    ans+=(rf*lt + rt*lf);
                }else{
                    ans+=(rt*lt + rf*lf);
                }
            }
        }

        return mp[temp] = ans;
    }
}
// Recursion based soln
int solve(string s, int i, int j, bool flag){
    // Base Conditions
    if(i>j) return 0;
    if(i == j){
        if(flag){
            return s[i] == 'T';
        }else{
            return s[i] == 'F';
        }
    }
    // K loop
    int ans = 0;
    for(int k=i+1;k<=j-1;k+=2){
        int lt = solve(s,i,k-1,true);
        int lf = solve(s,i,k-1,false);
        int rt = solve(s,k+1,j,true);
        int rf = solve(s,k+1,j,false);

        // Finding answer
        if(s[k] == '&'){
            if(flag){
                ans+=(lt*rt);
            }else{
                ans+=(lt*rf + lf*rt + lf*rf);
            }
        }
        else if(s[k] == '|'){
            if(flag){
                ans+=(lt*rt + lt*rf + lf*rt);
            }else{
                ans+=(lf*rf);
            }
        }else{
            if(flag){
                ans+=(lt*rf + lf*rt);
            }else{
                ans+=(lt*rt + lf*rf);
            }
        }
    }
    return ans;
}

int main(){
    string s = "T^F&T";
    mp.clear();
    int ans = solveMemo(s,0,s.length()-1,true);
    cout<<ans;
    return 0;
}