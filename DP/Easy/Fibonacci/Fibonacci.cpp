#include<bits/stdc++.h>
using namespace std;

// Memoization TC: O(n) SC: O(n) + O(n) for recursion stack
int solve(int n, vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}

// Tabulation TC: O(n) SC: O(n)
int solve(int n, vector<int>&dp){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// Space Optimized TC: O(n) SC: O(1)
int solve(int n){
    int prev=0,prev2=1;
    for(int i=2;i<=n;i++){
        int curr = prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return prev;
}





int main(){
    int n=5;
    vector<int> dp(n+1,-1);
    int ans = solve(n,dp);
    cout<<ans<<endl;
    //for space optimized
    int ans1=solve(n);
    cout<<ans1<<endl;
    return 0;
}