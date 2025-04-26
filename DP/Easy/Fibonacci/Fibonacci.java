import java.util.*;
class FibonacciCalculator {

    static int solve(int n, int[] dp){
        if(n<=1) return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }


    public static void main(String args[]) {

    int n=10;
    int dp[]=new int[n+1];
    Arrays.fill(dp,-1);
    
    //memoization tc=O(n) sc=O(n)+O(n)
   // System.out.println(solve(n,dp));


   //tabulation tc=O(n) sc=O(n)
    // dp[0]= 0;
    // dp[1]= 1;
  
    // for(int i=2; i<=n; i++){
    //     dp[i] = dp[i-1]+ dp[i-2];
    // }
    // System.out.println(dp[n]);

    //space optimization tc=O(n) sc=O(1)
    int prev2=0,prev1=1;
    for(int i=2;i<=n;i++){
        int curr = prev2+prev1;
        prev2=prev1;
        prev1=curr;
    }
    System.out.println(prev1);
    }
}