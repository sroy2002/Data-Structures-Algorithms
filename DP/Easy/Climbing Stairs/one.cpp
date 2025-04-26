//memoization TC:O(N) OC:O(N)+O(N)
int solve(int n, vector<int>&dp){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}

// tabulation TC:O(N) SC: O(N)
int solve(int n, vector<int>&dp){
    if(n<=1) return 1;
    dp[0]=1,dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//Space Optimization TC:O(N) SC:O(1)

int solve(int n){
    int prev=1,prev2=1;

    for(int i=2;i<=n;i++){
        int curr = prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int main(){
    int n=5;
    vector<int>dp(n+1,-1);
    //memoization & tabulation
    // int ans = solve(n,dp);

    //spcae optimization
    int ans = solve(n);
    cout<<ans<<endl;
    return 0;
}