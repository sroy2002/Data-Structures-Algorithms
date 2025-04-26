 //memoization TC: O(N) SC: O(N)+O(N)=O(N)
int solve(int n,vector<int>&dp, vector<int>& en){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int left = solve(n-1,dp,en) + abs(en[n]-en[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = solve(n-2,dp,en) + abs(en[n]-en[n-2]);
    }
    return dp[n]=min(left,right);
}
//tabulation tc: O(n) sc:O(n)
int solve2(int n, vector<int>&dp, vector<int>&en){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int left = dp[i-1]+abs(en[i]-en[i-1]);
        int right =INT_MAX;
        if(i>1){
            right = dp[i-2]+abs(en[i]-en[i-2]);
        }
        dp[i]=min(left,right);
    }
    return dp[n-1];
}
 //space optimization TC: O(N SC:O(1)
int solve3(int n){
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
  }
  return prev;
}

int main(){
    vector<int> height{30,10,60,10,60,50};
    int n=height.size();
    //memoization
   cout << solve(n,dp,height);
    //tabulation
    cout <<  solve2(n,dp,height);
    //space optimization
    cout << solve3(n,height);
    return 0;
}
