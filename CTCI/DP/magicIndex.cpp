// A[0...n-1] is a given array of length n
// Magic Index is the index where A[i] = i
// All the elements in the array are sorted
// Find the magic index
#include<bits/stdc++.h>
using namespace std;
int magicIndexHelper(int arr[],int n,int l, int r){
    int m = l + (r-l)/2;
    if(l<r) return -1;
    if(arr[m] == m) return m;
    if(arr[m]<m){
        // Magic index is on the right side
        return magicIndexHelper(arr,n,m+1,r);
    }else{
        // Magic index is on the left side
        return magicIndexHelper(arr,n,l,m-1);
    }
}
// If the array contains duplicate values
int magicIndexHelperUpdated(int arr[],int n,int l,int r){
    if(l>r) return -1;
    int midIndex = l + (r-l)/2;
    int midValue = arr[midIndex];
    if(midIndex == midValue){
        return midIndex;
    }else{
        // Search on the left side
        int leftIndex = min(midIndex,midValue);
        int left = magicIndexHelperUpdated(arr,n,l,leftIndex);
        if(left!= -1){
            return left;
        }else{
            // Search on the right side
            int rightIndex = max(midIndex,midValue);
            int right = magicIndexHelperUpdated(arr,n,right,r);
            cout<<rightIndex<<endl;
            return right;
        }
    }

}
int magicIndex(int arr[],int n){
    return magicIndexHelperUpdated(arr,n,0,n-1);
}
int findMagicUtil(vector<int> v, int start, int end){
	
	int n = v.size();

	if (start<0  || end>=v.size()){		// index out of bounds
		return -1;
	}
	
	if (start>end){
		return -1;	
	}

	int mid = start + (end-start)/2;
	if (mid==v[mid]){
	 	return mid;
	} 
	else{
		if (findMagicUtil(v,start,min(v[mid],mid))!=-1){
			return findMagicUtil(v,start,min(v[mid],mid));
		}
		
		return (findMagicUtil(v,max(v[mid],mid),end));
	}
}

int findMagic(vector<int> v){

	int n = v.size();
	if(n==0){
		return -1;
	}

	return findMagicUtil(v,0,n-1);
}
int main(){
    // test case 1
    // int arr[] = {-40,-20,-1,1,2,3,5,7,9,12,13}; 
    // Test Case 2
    vector<int>v = {-10,-5,2,2,2,3,4,7,9,12,13};
    cout<<findMagic(v);
    return 0;
}