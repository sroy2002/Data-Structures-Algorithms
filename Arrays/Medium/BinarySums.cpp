// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// A subarray is a contiguous part of the array.


//Time Complexity: O(n) and Space Complexity: O(n)

class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            int totalCount = 0;
            int currentSum = 0;
            // {prefix: number of occurrence}
            unordered_map<int, int> freq; // To store the frequency of prefix sums
    
            for (int num : nums) {
                currentSum += num;
                if (currentSum == goal){
                    totalCount++;
                }
                // Check if there is any prefix sum that can be subtracted from the current sum to get the desired goal
                if (freq.find(currentSum - goal) != freq.end()){
                    totalCount += freq[currentSum - goal];
                }
    
                freq[currentSum]++;
            }
    
            return totalCount;
        }
    };


//Time Complexity: O(n) and Space Complexity: O(1)


class Solution {
    private:
        int cntSubarrays(vector<int>&nums,int goal){
            if(goal<0)return 0;
            int n = nums.size();
            int l=0,r=0,sum=0,cnt=0;
            while(r<n){
                sum+=nums[r];
                while(sum>goal){
                    sum = sum-nums[l];
                    l++;
                }
                cnt=cnt+(r-l+1);
                r++;
            }
            return cnt;
        }
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return cntSubarrays(nums,goal)-cntSubarrays(nums,goal-1);
        }
    };