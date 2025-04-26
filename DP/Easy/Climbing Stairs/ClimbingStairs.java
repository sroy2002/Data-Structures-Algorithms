
import java.util.Arrays;

public class ClimbingStairs {
    //memoization TC: O(N) SC: O(N)+O(N)=O(N)
    public static int solve(int n, int[] dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1, dp)+solve(n-2,dp);
    }
    //tabulation tc: O(n) sc:O(n)
    public static int solve2(int n, int[] dp){
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    //space optimization TC: O(N SC:O(1)
    public static int solve3(int n){
        int prev2=1,prev=1;
        for(int i=2;i<=n;i++){
            int curr = prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    public static void main(String[] args) {
        int n=5;
        //memoization & tabulation
        int dp[] = new int[n+1];
        Arrays.fill(dp,-1);
        //memoization
        System.out.println(solve(n,dp));
        //tabulation
        System.out.println(solve2(n, dp));
        //space optimization
        System.out.println(solve3(n));
    }
}
