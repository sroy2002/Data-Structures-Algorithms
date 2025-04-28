// Frog Jump with K Steps

int solve1(int n, int k, vector<int>&h, vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int mmSteps = INT_MAX;
    for(int j=1;j<=k;j++){
        if(n-j>=0){
            int jump = solve1(n-j,k,h,dp) + abs(h[n]-h[n-j]);
            mmSteps = min(mmSteps,jump);
        }
    }
    return dp[n]=mmSteps;
}

int solve2(int n, int k, vector<int>&h, vector<int>&dp){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        for(int j=1;j<=k;j++){
            if((i-j)>=0){
                int jump = dp[i-j] + abs(h[i]-h[i-j]);
                mmSteps = min(mmSteps,jump);
            }
        }
        dp[i]=mmSteps;
    }
    return dp[n-1];
}


int main(){
    vector<int> h = {10,20,30,10};
    int n = h.size();
    int k = 3;
    vector<int> dp(n,-1);
    // memoization
    cout << solve1(n,k,h,dp);
    // tabulation
    cout << solve2(n,k,h,dp);
}