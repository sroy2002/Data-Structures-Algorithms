public class Solution {
    
    public static long solve(int start, int end, int[] arr){
        long prev2 = 0;
        long prev = arr[start];
        for(int i = start + 1; i <= end; i++){
            long pick = arr[i] + prev2;
            long notpick = prev;
            long curr = Math.max(pick, notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    public static long houseRobber(int[] valueInHouse) {
        int n = valueInHouse.length;
        if(n == 1) return valueInHouse[0];
        long ans1 = solve(0, n - 2, valueInHouse);
        long ans2 = solve(1, n - 1, valueInHouse);
        return Math.max(ans1, ans2);
    }	
}
