/****
 * Given an array arr[] consisting of 4 integers each between [1-9], the task is to 
 * check whether it is possible to get the number 24 by placing 
 * the operators +, –, /, and * between the numbers or grouping them using parenthesis. 
 * If it is possible then print “Possible“, Otherwise print “Not Possible”. 
 ****/
#include<bits/stdc++.h>
using namespace std;
#define tol 0.01
bool isPossibleUtil(double op1,double op2){
    if((abs(op1+op2 - 24.0)<tol) || (abs(op1-op2-24.0)<tol) || (abs(op1*op2 - 24.0)<tol) || op2 && (abs(op1/op2 - 24.0)<tol)){
        return true;
    } 
    else {
        return false;
    }
}

bool isPossible3Util(double op1,double op2, double op3){
    if(isPossibleUtil(op1+op2,op3)|| isPossibleUtil(op1-op2,op3) || isPossibleUtil(op1*op2,op3) || op2 && isPossibleUtil(op1/op2,op3)){
        return true;
    }
    if (isPossibleUtil(op2 + op3, op1) || isPossibleUtil(op2 - op3, op1) || isPossibleUtil(op2 * op3, op1) || op3 && isPossibleUtil(op2 / op3, op1))
    {
        return true;
    }
    return false;
}

bool solve(int arr[],int n){
    // Apply every operation between first two operands
    if (isPossible3Util(arr[0] + arr[1], arr[2], arr[3]) || isPossible3Util(arr[0] - arr[1], arr[2], arr[3]) || isPossible3Util(arr[0] * arr[1], arr[2], arr[3]) || arr[1] && isPossible3Util(arr[0] / arr[1], arr[2], arr[3]))
        return true;
    // Between second and third operands
    if (isPossible3Util(arr[0], arr[1] + arr[2], arr[3]) || isPossible3Util(arr[0], arr[1] - arr[2], arr[3]) || isPossible3Util(arr[0], arr[1] * arr[2], arr[3]) || arr[2] && isPossible3Util(arr[0], arr[1] / arr[2], arr[3]))
        return true;
    // Between third and fourth operands
    if (isPossible3Util(arr[0], arr[1], arr[2] + arr[3]) || isPossible3Util(arr[0], arr[1], arr[2] - arr[3]) || isPossible3Util(arr[0], arr[1], arr[2] * arr[3]) || arr[3] && isPossible3Util(arr[0], arr[1], arr[2] / arr[3]))
        return true;

    return false;
}

int main(){
    int arr[] = {3, 6, 8, 2};

    // Function Call
    if (solve(arr,4))
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }

    return 0;
}