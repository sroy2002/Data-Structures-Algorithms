import java.util.*;

public class FrogJump2 {
    static int solve1(int n, int k, int[] h, int[] dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int mmSteps = Integer.MAX_VALUE;
        for(int j=1;j<n;j++){
            if((n-j)>=0){
                int jump = solve1(n-j,k,h,dp) + Math.abs(h[n]-h[n-j]);
                mmSteps=Math.min(jump,mmSteps);
            }
        }
        return dp[n]=mmSteps;
    }
    static int solve2(int n, int k, int[] h, int[] dp){
        dp[0]=0;
        for(int i=1;i<n;i++){
            int mmSteps = Integer.MAX_VALUE;
            for(int j=1;j<=k;j++){
                if((i-j)<=0){
                    int jump = dp[i-j]+Math.abs(h[i]-h[i-j]);
                    mmSteps = Math.min(mmSteps,jump);
                }
            }
            dp[i]=mmSteps;
        }
        return dp[n-1];
    }
   public static void main(String[] args) {
       int h[]={10,20,30,10};
       int n = h.length;
       int k=3;
       int dp[] = new int[n];
       Arrays.fill(dp,-1);

       //memoization
       System.out.println(solve1(n,k,h,dp));
       //tabulation
       System.out.println(solve2(n,k,h,dp));
   }
}
