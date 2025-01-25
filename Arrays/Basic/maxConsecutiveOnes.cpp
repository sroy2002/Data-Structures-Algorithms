// Given a binary array nums, return the maximum number of consecutive 1's in the array.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int maxSum = 0;
       int cnt = 0;
       for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                cnt=0;
            }
        maxSum = max(maxSum,cnt);
       }
       return maxSum; 
    }
};