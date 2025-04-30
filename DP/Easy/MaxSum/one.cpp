#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>&arr, vector<int>&dp){
    if(dp[n]!=-1) return dp[n];
    if(n==0) return arr[0];
    if(n<0) return 0;
    int pick = arr[n] + solve(n-2,arr,dp);
    int notpick = 0 + solve(n-1,arr,dp);
    return dp[n]=max(pick,notpick);
}

int solve2(int n, vector<int>&arr, vector<int>&dp){
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        int pick = arr[i];
        if(i>1) pick += dp[i-2];
        int notpick = dp[i-1];
        dp[i]=max(pick,notpick);
    }
    return dp[n-1];
}

int solve3(int n, vector<int>&arr){
    int prev2=0;
    int prev = arr[0];
    for(int i=1;i<n;i++){
        int pick=arr[i];
        if(i>1) pick+=prev2;
        int notpick = prev;
        int curr = max(pick,notpick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int main(){
    vector<int> arr = {2,4,1,9};
    int n = arr.size();
    vector<int> dp(n,-1);
    //recursion with memoization
    cout << solve(n-1,arr,dp);
    //tabulation
    cout << solve2(n-1,arr,dp);
    //space optimzation
    cout << solve3(n-1,arr);
}