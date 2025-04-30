import java.util.Arrays;

public class MaxSum {
    static int solve(int n, int[] arr, int[] dp){
        if(dp[n]!=-1) return dp[n];
        if(n==0) return arr[0];
        if(n<1) return 0;
        int pick = arr[n] + solve(n-2,arr,dp);
        int notpick = 0 + solve(n-1,arr,dp);
        return dp[n]=Math.max(pick,notpick);
    }

    static int solve2(int n, int[] arr, int[] dp){
        dp[0] = arr[0];
        for(int i=1;i<n;i++){
            int pick = arr[i];
            if(i>1) pick+=dp[i-2];
            int notpick = dp[i-1];
            dp[i]=Math.max(pick, notpick);
        }
        return dp[n-1];
    }

    static int solve3(int n, int[] arr){
        int prev2=0;
        int prev=arr[0];
        for(int i=1;i<n;i++){
            int pick = arr[i];
            if(i>1) pick+=prev2;
            int notpick = prev;
            int curr = Math.max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }

    public static void main(String[] args){
        int arr[] = {2,4,1,9};
        int n = arr.length;
        int dp[] = new int[n];
        Arrays.fill(dp, -1);
        //memoization
        System.out.println(solve(n-1,arr,dp));
        //tabulation
        System.out.println(solve2(n-1,arr,dp));
        //space optimization
        System.out.println(solve3(n-1,arr));
    }
}
