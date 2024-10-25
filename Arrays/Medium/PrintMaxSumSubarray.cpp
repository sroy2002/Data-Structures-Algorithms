// find and print the maximum sum of a subarray in the given array and print that subarray

#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int>&arr, int n){
    int maxi = INT_MIN;
    int sum = 0;
    int start;
    int ansStart=-1,ansEnd=-1;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum<0)sum=0;
    }
    cout << "The maximum subarray sum is = " << maxi << endl;
    for(int i=ansStart;i<=ansEnd;i++){
        ans.push_back(arr[i]);
    }

    return ans;
}


int main(){
    int n;
    cout << "enter the array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> ans  = solve(arr,n);
    cout << "The subarray with maximum sum: ";
    for(auto it:ans){
        cout << it << " ";
    }

    return 0;
}