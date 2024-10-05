class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Optimal Code using Binary Search TC: O(logN), SC: O(1)
        int low = 1, high = n;
        while(low<=high){
            long long int mid = (low+high)/2;
            long long int val = mid*mid;
            if(val<=n){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return high;

        // Brute Force Code TC: O(N), SC: O(1)
        // long long ans;
        // for(int i=1;i<=n;i++){
        //     long long val = i*i;
        //     if(val<=n) ans=i;
        //     else break;
        // }
        // return ans;
    }
};