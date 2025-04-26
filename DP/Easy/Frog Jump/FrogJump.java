
import java.util.Arrays;

public class FrogJump {
    //memoization TC: O(N) SC: O(N)+O(N)=O(N)
    public static int solve(int ind,int[] height,int[] dp){
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int jumpTwo = Integer.MAX_VALUE;
        int jumpOne= solve(ind-1, height,dp)+ Math.abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = solve(ind-2, height,dp)+ Math.abs(height[ind]-height[ind-2]);
    
        return dp[ind]=Math.min(jumpOne, jumpTwo);
    }
    //tabulation tc: O(n) sc:O(n)
    public static int solve2(int n, int[] dp, int[] height){
        dp[0]=0;
        for(int ind=1;ind<n;ind++){
            int jumpTwo = Integer.MAX_VALUE;
            int jumpOne= dp[ind-1] + Math.abs(height[ind]-height[ind-1]);
            if(ind>1)
                jumpTwo = dp[ind-2] + Math.abs(height[ind]-height[ind-2]);
    
            dp[ind]=Math.min(jumpOne, jumpTwo);
        }
        return dp[n-1];
    }
     //space optimization TC: O(N SC:O(1)
    public static int solve3(int n, int[] height){
        int prev=0;
        int prev2=0;
        for(int i=1;i<n;i++){
            
            int jumpTwo = Integer.MAX_VALUE;
            int jumpOne= prev + Math.abs(height[i]-height[i-1]);
            if(i>1)
              jumpTwo = prev2 + Math.abs(height[i]-height[i-2]);
          
            int cur_i=Math.min(jumpOne, jumpTwo);
            prev2=prev;
            prev=cur_i;
        }
        return prev;
    }
    public static void main(String[] args) {
        int height[]={30,10,60,10,60,50};
        int n=height.length;
        int dp[] = new int[n];
        Arrays.fill(dp,-1);
        //memoization
        System.out.println(solve(n,height,dp));
        //tabulation
        System.out.println(solve2(n,dp,height));
        //space optimization
        System.out.println(solve3(n,height));
    }
}
