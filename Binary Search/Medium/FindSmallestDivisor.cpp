// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// BRUTE FORCE TC: O(maxElement*size0fArray) SC: O(1)

class  Solution{
    public:
        int findSmallestDivisor(vector<int>& nums, int threshold){
            int n = nums.size();
            int maxN = *max_element(nums.begin(),nums.end());
            int ans = -1;
            for(int i=0;i<=maxN;i++){
                int sum = 0;
                for(auto it:nums){
                    sum+= ceil((double)it/(double)i);
                }
                if(sum<=threshold) ans = i;
            }
            return ans;
        }
}

// OPTIMAL TC: O(log(maxElement)+sizeofArray) SC: O(1)

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxN = *max_element(nums.begin(),nums.end());
        int low = 1, high = maxN;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int sum = 0;
            for(int i=0;i<n;i++){
                sum = sum + ceil((double)nums[i]/(double)mid);
            }
            if(sum<=threshold){
                ans = mid;
                high = mid-1;
            } 
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};