/****
 * Given the mobile numeric keypad. You can only press buttons 
 * that are up, left, right or down to the current button. 
 * You are not allowed to press bottom row corner buttons (i.e. * and # ).
 * Given a number N, find out the number of possible numbers of given length. 
 ****/
#include<bits/stdc++.h>
using namespace std;
vector<int>row = {0, 0, -1, 0, 1};
vector<int>col = {0, -1, 0, 1, 0};
int helper(vector<vector<char>>keypad, int i,int j, int N){
    if(N<=0){
        return 0;
    }
    if(N == 1){
        return 1;
    }
    int ans = 0;
    for(int move = 0;move<5;move++){
        int dx = i + row[move];
        int dy = j + col[move];

        if(dx>=0 && dx<=3 && dy>=0 && dy<=2 && keypad[dx][dy] != '#' && keypad[dx][dy] != '*'){
            ans+=helper(keypad,dx,dy,N-1);
        }
    }
    return ans;
}
int getCount(vector<vector<char>>keypad, int N){
    int m = keypad.size();
    int n = keypad[0].size();

    if(N == 0){
        return 0;
    }
    if(N == 1){
        return 10;
    }

    // For cases N>1
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(keypad[i][j] != '*' && keypad[i][j] != '#'){
                ans+=helper(keypad,i,j,N);
            }
        }
    }

    return ans;
}

int main(){
    vector<vector<char>> keypad = { {'1', '2', '3'},
                                    {'4', '5', '6'},
                                    {'7', '8', '9'},
                                    {'*', '0', '#'}
    };
    printf("Count for numbers of length %d: %d\n", 1, getCount(keypad, 1));
    printf("Count for numbers of length %d: %d\n", 2, getCount(keypad, 2));
    printf("Count for numbers of length %d: %d\n", 3, getCount(keypad, 3));
    printf("Count for numbers of length %d: %d\n", 4, getCount(keypad, 4));
    printf("Count for numbers of length %d: %d\n", 5, getCount(keypad, 5));
    return 0;
}